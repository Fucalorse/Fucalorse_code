#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;

struct peach
{
    private:
        int n;
        vector<LL>op;

        void dfs(int l,int r,int id,const int &x,const LL &k)
        {
            if(l==r)
            {
                op[id]=min(op[id],k);
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);

            op[id]=min(op[hl],op[hr]);
        }

        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return INF;
            if(st<=l&&r<=ed) return op[id];

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return min(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        peach(int _n) { n=_n,op.assign((n+90)<<2,INF); }

        void update(int x,LL k) { dfs(1,n,1,x,k); }

        LL get(int st,int ed) { return query(1,n,1,st,ed); }
};

int n,mod;
LL a[MAX],c[MAX],sum[MAX];

void solve()
{
    cin>>n>>mod;

    int st=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=(sum[i-1]+a[i])%mod;
        if(st==-1&&sum[i]==0) st=i;
    }
    for(int i=1;i<=n;i++)
        cin>>c[i];
    
    int cnt=0;
    vector<bool>vis(n+1,false);
    unordered_map<LL,int>f;
    vector<int>pre(n+1,2e9);

    if(st!=-1)
    {
        for(int i=st;i<=n;i++)
            vis[i]=true;
    }

    for(int i=1,l=1;i<=n;i++)
    {
        if(++f[sum[i]]==1) ++cnt;

        while(l<=n&&cnt==mod)
        {
            if(--f[sum[l]]==0) --cnt;
            ++l;
        }

        pre[i]=l;
    }

    peach fu(n);
    vector<LL>dp(n+1,INF);
    dp[0]=0;

    if(sum[1]==0) dp[1]=dp[0]+c[1];
    else dp[1]=dp[0];
    fu.update(1,dp[0]+c[1]);

    for(int i=2;i<=n;i++)
    {
        fu.update(i,dp[i-1]+c[i]);
        if(pre[i]==1)
        {
            if(vis[i]) dp[i]=fu.get(pre[i],i);
            else dp[i]=0LL;
        }
        else dp[i]=fu.get(pre[i],i);
    }

    // for(int i=1;i<=n;i++)
    //     cout<<dp[i]<<' ';
    // cout<<endl;

    cout<<dp[n]<<endl;
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