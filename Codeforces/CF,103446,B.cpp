#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e5,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,LL p)
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

void ntt(vector<LL>& a,bool inverse)
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

vector<LL> multiply(const vector<LL>& a,const vector<LL>& b)
{
    if((LL)a.size()*(LL)b.size()<=400)
    {
        int len=a.size()+b.size()-1;
        vector<LL>ans(len);

        for(int i=0;i<(int)a.size();i++)
            for(int j=0;j<(int)b.size();j++)
                ans[i+j]=(ans[i+j]+a[i]*b[j]%MOD)%MOD;

        return ans;
    }

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

int dfn[MAX],low[MAX];
bool vis[MAX];
vector<int>st;
int cnt[MAX],scc,tot;

void dfs(int u,vector<vector<int>>& adj)
{
    dfn[u]=low[u]=++tot;
    st.push_back(u);
    vis[u]=true;

    for(auto &v:adj[u])
    {
        if(!dfn[v])
        {
            dfs(v,adj);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }

    if(low[u]==dfn[u])
    {
        ++scc;

        while(1)
        {
            int v=st.back();st.pop_back();
            vis[v]=false;
            cnt[scc]++;
            if(u==v) break;
        }
    }
}

struct qwq
{
    vector<LL>op;
    bool operator<(const qwq &a)const { return op.size()>a.op.size(); }
};

int n;
int p[MAX];
LL fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return fac[n]*inv[n-m]%MOD*inv[m]%MOD; }
LL A(int n,int m) { return fac[n]*inv[n-m]%MOD; }

void solve()
{
    cin>>n;

    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        adj[i].push_back(p[i]);
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i,adj);

    priority_queue<qwq>q;
    for(int i=1;i<=scc;i++)
    {
        vector<LL>op(cnt[i]);
        for(int j=0;j<cnt[i];j++)
            op[j]=C(cnt[i],j);
        q.push({op});
    }

    while((int)q.size()>1)
    {
        auto [a]=q.top();q.pop();
        auto [b]=q.top();q.pop();
        q.push({multiply(a,b)});
    }

    LL del=0;
    vector<LL>op=q.top().op;
    for(int i=1;i<(int)op.size();i++)
    {
        LL now=fac[n-i]*op[i]%MOD;
        if(i%2==0) now=(-now+MOD)%MOD;
        del=(del+now)%MOD;
    }

    LL ans=(fac[n]-del+MOD)%MOD;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}