#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9,mod=998244353;

struct peach
{
    private:
        int size;
        vector<LL>op;
    public:
        peach(int n) { size=n,op.assign(n+3,0); }

        void update(int n,LL k)
        {
            while(n<=size)
            {
                op[n]=(op[n]+k)%mod;
                n+=n&-n;
            }
        }

        LL query(int n)
        {
            LL ans=0;

            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }

            return ans;
        }

        LL query_range(int l,int r)
        {
            if(l>r) return 0LL;
            else
            {
                LL ans=(query(r)-query(l-1))%mod;
                return (ans+mod)%mod;
            }
        }
};

int T,n;
int maxn[MAX],deg[MAX];
bool ok[MAX];
LL dp[MAX];
vector<int>p[MAX];

void dfs1(int ch,int fa)
{
    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs1(to,ch);
        maxn[ch]=max(maxn[ch],max(maxn[to],to));
    }
}

void dfs2(int ch,int fa,set<int>&st)
{
    if(st.size()&&ch>*st.rbegin()) ok[ch]=true;

    for(auto &to:p[ch])
    {
        if(to==fa) continue;

        dfs2(to,ch,st);
    }
}

void clear()
{
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;
        deg[i]=0;
        maxn[i]=-inf;
        ok[i]=false;

        p[i].clear();
    }
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        p[u].push_back(v);
        p[v].push_back(u);

        ++deg[u],++deg[v];
    }

    int pos=0;
    for(int i=n;i>=1;i--)
        if(deg[i]==1)
        {
            pos=i;
            break;
        }

    dfs1(n,0);

    dp[pos]=1;
    peach fu(n);
    fu.update(pos,dp[pos]);

    // for(int i=1;i<=n;i++)
    //     cout<<maxn[i]<<' ';
    // cout<<endl;

    // cout<<pos<<endl;

    for(int i=pos+1;i<n;i++)
    {
        int l=maxn[i]+1,r=i-1;

        if(l<=r)
        {
            dp[i]=(dp[i]+fu.query_range(l,r))%mod;
            fu.update(i,dp[i]);
        }
    }

    set<int>st;
    for(auto &cur:p[n])
        st.insert(max(maxn[cur],cur));

    // for(auto &cur:st)
    //     cout<<cur<<' ';
    // cout<<endl;

    for(auto &cur:p[n])
    {
        st.erase(max(maxn[cur],cur));
        dfs2(cur,n,st);
        st.insert(max(maxn[cur],cur));
    }

    for(int i=1;i<n;i++)
        if(ok[i]) dp[n]=(dp[n]+dp[i])%mod;

    cout<<dp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}