#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e5+10,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int pool[MAX],pool_id;

struct fucalorse
{
    private:
        int n,tot,total;
        vector<int>op;

        void create(int l,int r,int id,int fa,vector<vector<int>>& adj)
        {
            op[id]=++tot;
            if(fa)
            {
                adj[op[id]].push_back(op[fa]);
                adj[op[fa]+total].push_back(op[id]+total);
            }
            if(l==r) return;

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,id,adj);
            create(mid+1,r,hr,id,adj);
        }

        void query(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                pool[++pool_id]=op[id];
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) query(l,mid,hl,st,ed);
            if(mid<ed) query(mid+1,r,hr,st,ed);
        }
    public:
        fucalorse(int _n,int _st_id,vector<vector<int>>& adj)
        {
            n=_n,tot=_st_id;
            total=3*n-1;
            op.assign((n+90)<<2,0);
            create(1,n,1,0,adj);
        }

        void get_id(int st,int ed) { pool_id=0,query(1,n,1,st,ed); }
};

int n,m;
int f[MAX],x[MAX],y[MAX],depth[MAX],tin[MAX],tout[MAX],rev[MAX];

void solve()
{
    cin>>n;

    int timer=0;
    vector<vector<int>>adj(n+1);
    vector<vector<int>>node(n+1);
    
    for(int i=2;i<=n;i++)
    {
        cin>>f[i];
        adj[i].push_back(f[i]);
        adj[f[i]].push_back(i);
    }

    auto dfs_first=[&](auto &&self,int ch,int fa)->void
    {
        depth[ch]=depth[fa]+1;
        tin[ch]=++timer;
        rev[timer]=ch;
        node[depth[ch]].push_back(tin[ch]);
        
        for(auto &to:adj[ch])
        {
            if(to==fa) continue;
            self(self,to,ch);
        }

        tout[ch]=timer;
    };

    dfs_first(dfs_first,1,0);
    int node_number=3*n-1,total_node=2*node_number;
    vector<vector<int>>nadj(total_node+1);
    vector<pair<int,int>>range(n+1);
    fucalorse fu(n,n,nadj);

    for(int u=2;u<=n;u++)
    {
        int v=f[u];
        nadj[u+node_number].push_back(v);
        nadj[v+node_number].push_back(u);
    }

    for(int i=1,tot=0;i<=n;i++)
    {
        auto &op=node[i];
        if(op.empty()) break;
        range[i]={tot+1,tot+(int)op.size()};
        
        for(auto &cur:op)
        {
            ++tot;
            int u=rev[cur];
            fu.get_id(tot,tot);
            int p=pool[1];

            nadj[u].push_back(p);
            nadj[p].push_back(u);
            nadj[u+node_number].push_back(p+node_number);
            nadj[p+node_number].push_back(u+node_number);
        }
    }

    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        int target=depth[x[i]]+y[i];
        if(target<=n&&node[target].size())
        {
            auto &op=node[target];
            auto itl=lower_bound(op.begin(),op.end(),tin[x[i]])-op.begin();
            auto itr=upper_bound(op.begin(),op.end(),tout[x[i]])-op.begin();
            if(itl!=itr)
            {
                int st=range[target].first+itl,ed=range[target].first+itr-1;
                fu.get_id(st,ed);
                for(int j=1;j<=pool_id;j++)
                {
                    nadj[x[i]].push_back(pool[j]+node_number);
                    nadj[pool[j]].push_back(x[i]+node_number);
                }
            }
        }
    }

    int tot=0,scc=0;
    vector<bool>vis(total_node+1,false);
    vector<int>st;
    vector<int>dfn(total_node+1,0),low(total_node+1,0),belong(total_node+1,0);

    auto tarjin=[&](auto &&self,int u)->void
    {
        dfn[u]=low[u]=++tot;
        vis[u]=true;
        st.push_back(u);

        for(auto &v:nadj[u])
        {
            if(!dfn[v])
            {
                self(self,v);
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
                belong[v]=scc;
                if(u==v) break;
            }
        }
    };

    for(int i=1;i<=total_node;i++)
        if(!dfn[i]) tarjin(tarjin,i);

    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(belong[i]==belong[i+node_number])
        {
            cout<<"No"<<endl;
            return;
        }

        if(belong[i]<belong[i+node_number]) ans.push_back(i);
    }

    cout<<"Yes"<<endl;
    cout<<ans.size()<<endl;
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