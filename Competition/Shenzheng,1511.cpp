#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=200;
const LL inf=1e18;

struct qwq
{
    int id;
    LL val;
    bool operator<(const qwq &a)const { return val<a.val; }
}op[MAX];

int n,k,q;
LL a[MAX];

auto merge(const vector<vector<LL>>&a,const vector<vector<LL>>&b)
{
    vector<vector<LL>>ans(n+3,vector<LL>(n+3,inf));
    for(int to=1;to<=n;to++)
        for(int i=1;i<=n;i++)
        {
            if(a[i][to]==inf) continue;
            for(int j=1;j<=n;j++)
            {
                if(b[to][j]==inf) continue;
                ans[i][j]=min(ans[i][j],a[i][to]+b[to][j]);
            }
        }
    return ans;
}

auto cal(vector<vector<LL>>&a,int p)
{
    vector<vector<LL>>ans(n+3,vector<LL>(n+3,inf));
    for(int i=1;i<=n;i++)
        ans[i][i]=0;
    while(p)
    {
        if(p&1) ans=merge(ans,a);
        a=merge(a,a);
        p>>=1;
    }
    return ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]={i,a[i]};
    }
    sort(op+1,op+n+1);
    vector<vector<LL>>dp(n+3,vector<LL>(n+3,inf)),f(n+3,vector<LL>(n+3,inf));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>f[i][j];
            if(f[i][j]==-1) f[i][j]=inf;
            if(i!=j) dp[i][j]=f[i][j];
        }
    for(int p=1;p<=n;p++)
    {
        int to=op[p].id;
        for(int i=1;i<=n;i++)
        {
            if(f[i][to]==inf) continue;
            for(int j=1;j<=n;j++)
            {
                if(f[to][j]==inf) continue;
                f[i][j]=min(f[i][j],f[i][to]+f[to][j]);
                if(i!=j&&a[to]<min(a[i],a[j])) dp[i][j]=min(dp[i][j],f[i][j]);
            }
        }
    }
    vector<vector<LL>>ans=cal(dp,k);
    cin>>q;
    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<(ans[u][v]==inf?-1:ans[u][v])<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}