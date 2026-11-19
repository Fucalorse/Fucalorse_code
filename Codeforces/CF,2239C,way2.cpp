#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=18,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        int n;
        vector<LL>op;
    public:
        peach(int _n) { n=_n,op.assign(n+3,0); }

        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]+=k;
        }

        LL query(int pos)
        {
            LL ans=0;
            for(int i=pos;i;i-=i&-i)
                ans+=op[i];
            return ans;
        }

        LL get(int pos) { return op[pos]; }
};

int n;
LL num[MAX];
char type[MAX];

void solve()
{
    cin>>n;

    vector<int>pos;
    pos.push_back(0);

    for(int i=1;i<=n;i++)
    {
        cin>>type[i]>>num[i];
        if(type[i]=='s') pos.push_back(i);
    }

    int len=pos.size();
    vector<int>pre(n+1,0);
    for(int i=1;i<len;i++)
        pre[pos[i]]=pos[i-1];

    peach C(n),A(n);
    vector<int>ans(n+1,0);
    vector<bool>del(n+1,false);
    for(int i=1;i<=n;i++)
        C.update(i,1);

    auto find=[&](LL target)
    {
        LL sum=0;
        int pos=0;
        for(int k=LEN;k>=0;k--)
        {
            int aft=pos|(1<<k);
            if(aft<=n)
            {
                LL now=C.get(aft)+2*A.get(aft);
                if(sum+now<target)
                {
                    sum+=now;
                    pos=aft;
                }
            }
        }
        return pos+1;
    };

    for(int i=n;i>=1;i--)
    {
        if(type[i]=='p')
        {
            ans[i]=num[i];
            if(!del[num[i]])
            {
                del[num[i]]=true;
                C.update(num[i],-1);
            }
            continue;
        }

        LL target=0;
        int l=pre[i]+1,r=i-1;
        for(int cur=r;cur>=l;cur--)
        {
            del[num[cur]]=true;
            target+=C.query(n)-C.query(num[cur]);
            C.update(num[cur],-1);
            A.update(num[cur],1);
        }
        target+=r-l+1+C.query(n)-(num[r+1]-num[l-1]);

        ans[i]=find(target);
        C.update(ans[i],-1);

        for(int cur=r;cur>=l;cur--)
            A.update(num[cur],-1);
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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