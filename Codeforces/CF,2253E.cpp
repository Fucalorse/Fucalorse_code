#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }

    return ans;
}

void ntt(vector<LL> &a,bool inverse)
{
    int n=a.size();

    for(int i=1,j=0;i<n;i++)
    {
        int bit=n>>1;
        while(j&bit)
        {
            j^=bit;
            bit>>=1;
        }

        j^=bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1)
    {
        LL wlen=qpow(G,(MOD-1)/len);
        if(inverse) wlen=qpow(wlen,MOD-2);

        for(int i=0;i<n;i+=len)
        {
            LL w=1;
            
            for(int j=0;j<len/2;j++)
            {
                LL u=a[i+j],v=a[i+j+len/2]*w%MOD;

                a[i+j]=(u+v)%MOD;
                a[i+j+len/2]=(u-v+MOD)%MOD;

                w=w*wlen%MOD;
            }
        }
    }

    if(inverse)
    {
        LL inv=qpow(n,MOD-2);
        for(auto &cur:a)
            cur=cur*inv%MOD;
    }
}

vector<LL> multiply(const vector<LL> &a,const vector<LL> &b)
{
    vector<LL>fa(a.begin(),a.end()),fb(b.begin(),b.end());
    int n=1,len=a.size()+b.size()-1;
    while(n<len) n<<=1;

    fa.resize(n),fb.resize(n);

    ntt(fa,false);
    ntt(fb,false);

    for(int i=0;i<n;i++)
        fa[i]=fa[i]*fb[i]%MOD;

    ntt(fa,true);
    fa.resize(len);

    return fa;
}

int n;
int depth[MAX],f[MAX],st,maxn;
LL dp[MAX],cnt[MAX];

void dfs_first(int ch,int fa,vector<vector<int>> &adj)
{
    f[ch]=fa;
    depth[ch]=depth[fa]+1;
    if(depth[ch]>maxn) maxn=depth[ch],st=ch;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs_first(to,ch,adj);
    }
}

void dfs(int ch,int fa,vector<LL> &op,vector<vector<int>> &adj)
{
    dp[ch]=cnt[ch]=0;
    depth[ch]=depth[fa]+1;

    for(auto &to:adj[ch])
    {
        if(to==fa) continue;
        dfs(to,ch,op,adj);

        dp[ch]+=cnt[ch]*cnt[to];
        cnt[ch]+=cnt[to];
    }

    if(depth[ch]==maxn/2)
    {
        cnt[ch]++;
        dp[ch]++;
    }

    op[depth[ch]]|=(dp[ch]>=1LL);
}

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    maxn=depth[0]=-1;
    dfs_first(1,0,adj);

    maxn=depth[0]=-1;
    dfs_first(st,0,adj);

    int now=0,left,right;
    for(int i=st;i;i=f[i],++now)
        if(now==maxn/2)
        {
            left=i;
            right=f[i];
            break;
        }

    vector<LL>a(n+1,0LL),b(n+1,0LL);
    
    depth[right]=-1;
    dfs(left,right,a,adj);
    depth[left]=-1;
    dfs(right,left,b,adj);

    vector<LL>op=multiply(a,b);
    vector<int>ans;

    for(size_t i=0;i<op.size();i++)
        if(op[i]) ans.push_back(i+1);

    cout<<ans.size()<<' ';
    for(auto &cur:ans)
        cout<<cur<<' ';
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