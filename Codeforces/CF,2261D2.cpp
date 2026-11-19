#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
#define ULL unsigned long long
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

mt19937_64 rng(random_device{}());

struct interval
{
    int l,r;
}op[MAX];

int n,m;
ULL Val[MAX];

void solve()
{
    cin>>n>>m;

    vector<ULL>f(2*n+1,0ULL);
    for(int i=1;i<=m;i++)
    {
        cin>>op[i].l>>op[i].r;
        Val[i]=rng();
        f[op[i].l]^=Val[i];
        f[op[i].r+1]^=Val[i];
    }
    for(int i=1;i<=n;i++)
        f[i]^=f[i-1];
    for(int i=n+1;i<=2*n;i++)
        f[i]=f[i-n];

    int S=2*n,size=31-__builtin_clz(S);
    map<ULL,int>cnt;
    vector<vector<int>>nxt(size+1,vector<int>(S+1,0));
    for(int l=1,r=1;l<=S;l++)
    {
        while(r<=S&&cnt[f[r]]==0)
        {
            ++cnt[f[r]];
            r++;
        }
        --cnt[f[l]];

        nxt[0][l]=r;
    }

    for(int k=1;k<=size;k++)
        for(int i=1;i<=S;i++)
            if(nxt[k-1][i]<=S) nxt[k][i]=nxt[k-1][nxt[k-1][i]];

    auto cal=[&](int st,int ed)->int
    {
        int pos=st,ans=0;
        for(int k=size;k>=0;k--)
        {
            int npos=nxt[k][pos];
            if(npos!=0&&npos<=ed)
            {
                pos=npos;
                ans|=1<<k;
            }
        }
        // cout<<st<<' '<<ed<<' '<<ans<<endl;
        return ans+1;
    };

    int minn=INF,pos=-1;
    for(int i=1;i<=n;i++)
    {
        int st=i,ed=i+n-1;
        int now=cal(st,ed);
        if(now<minn)
        {
            minn=now;
            pos=st;
        }
    }

    // cout<<minn<<' '<<pos<<endl<<endl;
    vector<interval>temp,rest;
    int ed=pos+n-1;
    while(pos<=ed)
    {
        int npos=nxt[0][pos];
        temp.push_back({pos,min(ed,npos-1)});
        pos=npos;
    }

    int cur=0,len=temp.size();
    for(int i=0;i<len;i++)
        if(temp[i].l<=n&&temp[i].r>n)
        {
            cur=i;
            break;
        }

    for(int i=cur+1;i<len;i++)
        rest.push_back(temp[i]);
    for(int i=0;i<cur;i++)
        rest.push_back(temp[i]);

    len=rest.size();
    if(!len)
    {
        cout<<0<<endl;
        return;
    }

    if(len==1)
    {
        cout<<1<<endl;
        cout<<rest[0].l<<' '<<rest[0].r<<endl;
        return;
    }

    vector<interval>ans={{rest[0].l,rest[1].r}};
    for(int l=1;l<len-1;l+=2)
    {
        int r=min(l+2,len-1);
        ans.push_back({rest[l].l,rest[r].r});
    }

    if(len%2==0) ans.push_back(rest.back());

    cout<<ans.size()<<endl;
    for(auto &[l,r]:ans)
        cout<<l<<' '<<r<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}