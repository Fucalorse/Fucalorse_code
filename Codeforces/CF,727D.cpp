#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const LL INF=9e18;

struct dinic
{
    private:
        struct Edge
        {
            int to;
            LL cap;
        };

        int n,s,t;
        vector<Edge>edge;
        vector<vector<int>>adj;
        vector<int>level,cur;

        bool bfs()
        {
            fill(level.begin(),level.end(),-1);

            queue<int>q;
            level[s]=0;
            q.push(s);

            while(q.size())
            {
                int u=q.front();q.pop();

                for(auto &id:adj[u])
                {
                    auto [v,cap]=edge[id];
                    if(cap>0&&level[v]==-1)
                    {
                        level[v]=level[u]+1;
                        q.push(v);
                    }
                }
            }

            return level[t]!=-1;
        }

        LL dfs(int u,LL limit)
        {
            if(u==t) return limit;

            for(int &i=cur[u];i<(int)adj[u].size();i++)
            {
                int id=adj[u][i];
                auto [v,cap]=edge[id];

                if(cap==0||level[v]!=level[u]+1) continue;

                LL pushed=dfs(v,min(limit,cap));
                if(pushed>0)
                {
                    edge[id].cap-=pushed;
                    edge[id^1].cap+=pushed;
                    return pushed;
                }
            }

            return 0;
        }
    public:
        dinic(int _n,int _s,int _t):n(_n),s(_s),t(_t),adj(_n+1),level(_n+1),cur(_n+1){}

        void add_edge(int u,int v,LL cap)
        {
            int id=edge.size();

            edge.push_back({v,cap});
            edge.push_back({u,0});

            adj[u].push_back(id);
            adj[v].push_back(id^1);
        }

        LL max_flow()
        {
            LL ans=0;
            while(bfs())
            {
                fill(cur.begin(),cur.end(),0);
                while(LL pushed=dfs(s,INF))
                    ans+=pushed;
            }
            return ans;
        }

        vector<int> get()
        {
            vector<int>ans(t-7);

            for(int i=1;i<=6;i++)
                for(auto &id:adj[i])
                {
                    auto [v,cap]=edge[id];
                    if((id&1)==0&&v>=7&&v<t&&cap==0) ans[v-7]=i;
                }

            return ans;
        }
};

int n;
LL a[MAX];
map<string,int>mp;
map<int,string>rev;

void solve()
{
    for(int i=1;i<=6;i++)
        cin>>a[i];

    cin>>n;
    dinic fu(n+10,0,n+7);

    for(int i=1;i<=6;i++)
        fu.add_edge(0,i,a[i]);

    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;

        stringstream ss(s);
        string part;
        while(getline(ss,part,',')) fu.add_edge(mp[part],i+6,1);

        fu.add_edge(i+6,n+7,1);
    }

    if(fu.max_flow()>=n)
    {
        cout<<"YES"<<endl;
        vector<int>op=fu.get();
        for(auto &id:op)
            cout<<rev[id]<<endl;
    }
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    mp["S"]=1,rev[1]="S";
    mp["M"]=2,rev[2]="M";
    mp["L"]=3,rev[3]="L";
    mp["XL"]=4,rev[4]="XL";
    mp["XXL"]=5,rev[5]="XXL";
    mp["XXXL"]=6,rev[6]="XXXL";

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}