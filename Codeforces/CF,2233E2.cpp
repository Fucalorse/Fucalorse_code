#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9,LEN=24;

struct qwq
{
    int id,cnt;
    bool operator<(const qwq &a)const { return cnt>a.cnt; }
};

int T,n;
LL f[MAX];
string s[LEN];

void create()
{
    f[0]=1;
    for(int i=1;i<LEN;i++)
        f[i]=f[i-1]*i;
}

void solve()
{
    cin>>n;
    int k=0;
    while((1<<k)<n+1) k++;

    for(int i=1;i<=k;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }

    vector<qwq>op;
    for(int i=1;i<=k;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
            cnt+=s[i][j]=='1';
        op.push_back({i,cnt});
    }

    sort(op.begin(),op.end());
    vector<int>exist(1<<k,0);
    for(int i=1;i<=n;i++)
    {
        int mask=0;
        for(int j=0;j<k;j++)
            if(s[op[j].id][i]=='1') mask|=1<<j;
        
        if(mask>n||!mask||exist[mask])
        {
            cout<<0<<endl;
            return;
        }

        exist[mask]=1;
    }

    LL ans=1;
    for(int l=0,r;l<k;l=r)
    {
        r=l;
        while(r<k&&op[l].cnt==op[r].cnt) r++;
        ans*=f[r-l];
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}