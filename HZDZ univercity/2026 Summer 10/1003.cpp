#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1090,LEN=32,MOD=998244353;
const LL INF=1e18;

struct peach
{
    private:
        struct edge
        {
            int to,rev;
            LL cap;
        };

        int n;
        vector<vector<edge>>g;
        vector<int>dep,cur;
    public:
        peach(int _n)
        {
            n=_n;
            g.assign(n+1,vector<edge>{});
            dep.assign(n+1,0);
            cur.assign(n+1,0);
        }

        void add(int u,int v,LL cap)
        {
            edge eu={v,(int)g[v].size(),cap},ev={u,(int)g[u].size(),0};
            g[u].push_back(eu),g[v].push_back(ev);
        }

        bool bfs(int s,int t)
        {
            fill(dep.begin(),dep.end(),-1);

            queue<int>q;
            q.push(s),dep[s]=0;

            while(q.size())
            {
                int pos=q.front();q.pop();

                for(auto &[to,rev,cap]:g[pos])
                    if(cap>0&&dep[to]==-1)
                    {
                        dep[to]=dep[pos]+1;
                        q.push(to);
                    }
            }

            return dep[t]!=-1;
        }

        LL dfs(int u,int t,LL lim)
        {
            if(u==t) return lim;

            for(int &i=cur[u];i<(int)g[u].size();i++)
            {
                auto &[to,rev,cap]=g[u][i];

                if(cap>0&&dep[to]==dep[u]+1)
                {
                    LL flow=dfs(to,t,min(lim,cap));

                    if(flow>0)
                    {
                        cap-=flow;
                        g[to][rev].cap+=flow;
                        return flow;
                    }
                }
            }

            return 0;
        }

        LL max_flow(int s,int t)
        {
            LL ans=0;

            while(bfs(s,t))
            {
                fill(cur.begin(),cur.end(),0);

                while(LL flow=dfs(s,t,INF)) ans+=flow;
            }

            return ans;
        }
};

int n,k;
string s[MAX];

bool check(const int &mid)
{
    int S=0,T=n+k+1,V=n+k+2;
    peach fu(V);

    for(int i=1;i<=n;i++)
    {
        fu.add(S,i,1);

        for(int j=1;j<=k;j++)
            if(s[i][j]=='1') fu.add(i,n+j,1);
    }

    for(int i=1;i<=k;i++)
        fu.add(n+i,T,mid);

    if(fu.max_flow(S,T)>=mid*k) return true;
    else return false;
}

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]=' '+s[i];
    }

    int l=0,r=n/k;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    cout<<r<<endl;
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