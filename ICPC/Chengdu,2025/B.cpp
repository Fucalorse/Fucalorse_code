#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e18;

int T,n,r;
LL m,k,a[MAX],c[MAX],suma[MAX],sumc[MAX];

vector<vector<LL>> merge(vector<vector<LL>> &a,vector<vector<LL>> &b)
{
    int size=1<<n;
    vector<vector<LL>> ans(size,vector<LL>(size,-inf));
    for(int k=0;k<size;k++)
        for(int i=0;i<size;i++)
        {
            if(a[i][k]==-inf) continue;
            for(int j=0;j<size;j++)
            {
                if(b[k][j]==-inf) continue;
                ans[i][j]=max(ans[i][j],a[i][k]+b[k][j]);
            }
        }
    return ans;
}

vector<vector<LL>> cal(vector<vector<LL>> a,int p)
{
    int size=1<<n;
    vector<vector<LL>> ans(size,vector<LL>(size,-inf));
    for(int i=0;i<size;i++)
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
    cin>>n>>m>>k>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];

    int size=1<<n;
    vector<vector<LL>>dp(size,vector<LL>(size,-inf));
    for(int i=0;i<size;i++)
    {
        suma[i]=sumc[i]=0;
        for(int j=n-1;j>=0;j--)
            if((i>>j)&1)
            {
                suma[i]+=a[j+1];
                sumc[i]+=c[j+1];
            }
    }
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
        {
            bitset<10>pre=i&j;
            LL cost=sumc[j]+pre.count()*k;
            if(cost<=m) dp[i][j]=suma[j];
        }
    
    vector<vector<LL>> ans=cal(dp,r);
    LL maxn=-inf;
    for(int i=0;i<size;i++)
        maxn=max(maxn,ans[0][i]);
    cout<<maxn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}