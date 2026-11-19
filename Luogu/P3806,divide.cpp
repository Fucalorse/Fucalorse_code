#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,m;
int sz[MAX];
LL path[MAX],query[MAX];
bool vis[MAX],ok[MAX];

void get_size(int ch,int fa,vector<vector<pair<int,LL>>>& adj)
{
    sz[ch]=1;

    for(auto &[to,val]:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        get_size(to,ch,adj);
        sz[ch]+=sz[to];
        path[to]=path[ch]+val;
    }
}

int get_sent(int root,vector<vector<pair<int,LL>>>& adj)
{
    path[root]=0;
    get_size(root,0,adj);
    int half=sz[root]>>1,u=root,fa=0;

    while(1)
    {
        int nxt=-1;

        for(auto &[v,val]:adj[u])
        {
            if(v==fa||vis[v]) continue;
            if(sz[v]>half)
            {
                nxt=v;
                break;
            }
        }

        if(nxt==-1) return u;
        fa=u;
        u=nxt;
    }
}

void collect(int ch,int fa,unordered_set<LL>& st,vector<vector<pair<int,LL>>>& adj)
{
    st.insert(path[ch]);
    
    for(auto &[to,val]:adj[ch])
    {
        if(to==fa||vis[to]) continue;
        path[to]=path[ch]+val;
        collect(to,ch,st,adj);
    }
}

void solve()
{
    cin>>n>>m;

    vector<vector<pair<int,LL>>>adj(n+1);
    for(int i=1;i<n;i++)
    {
        int u,v;
        LL val;
        cin>>u>>v>>val;
        adj[u].push_back({v,val});
        adj[v].push_back({u,val});
    }

    for(int i=1;i<=m;i++)
        cin>>query[i];

    unordered_set<LL>st;
    auto cal=[&]()
    {
        queue<int>q;
        q.push(1);

        while(q.size())
        {
            int root=q.front();q.pop();
            int sent=get_sent(root,adj);
            vis[sent]=true;

            st.clear();
            st.insert(0);
            
            for(auto &[to,val]:adj[sent])
            {
                if(vis[to]) continue;

                unordered_set<LL>cur;
                path[to]=val;
                collect(to,sent,cur,adj);

                for(int i=1;i<=m;i++)
                {
                    if(ok[i]) continue;
                    
                    for(auto &d:cur)
                        if(st.count(query[i]-d))
                        {
                            ok[i]=true;
                            break;
                        }
                }

                for(auto &d:cur)
                    st.insert(d);
            }

            for(auto &[to,val]:adj[sent])
                if(!vis[to]) q.push(to);
        }
    };

    cal();
    for(int i=1;i<=m;i++)
    {
        if(ok[i]) cout<<"AYE"<<endl;
        else cout<<"NAY"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}