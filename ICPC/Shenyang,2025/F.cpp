#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=350,LEN=1e6+90;

struct edge
{
    int u,v;
}op[LEN],ans[LEN];

int T,n,m,x,y;
vector<pair<int,int>>p[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
        p[i].clear();
}

vector<int> find_circle(int st,int ed,int ban_id)
{
    queue<int>q;
    vector<int>pre(n+1,-1);

    q.push(st);
    pre[st]=0;

    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto &[v,id]:p[u])
        {
            if(id==ban_id) continue;
            if(pre[v]==-1)
            {
                pre[v]=u;
                q.push(v);
            }
        }
    }

    if(pre[ed]==-1) return {};
    else
    {
        vector<int>ans;
        for(int i=ed;i;i=pre[i])
            ans.push_back(i);
        reverse(ans.begin(),ans.end());
        return ans;
    }
}

bool get_ans(int u,vector<int> &root,vector<int> &pre,vector<int> &circle)
{
    vector<int>nxt(n+1,0);
    vector<bool>special_node(n+1,false);

    auto check=[&](int a,int b)
    {
        if(nxt[a]&&nxt[a]!=b) return false;
        nxt[a]=b;
        special_node[a]=special_node[b]=true;
        return true;
    };

    int leader=root[u];
    int follower=leader==x?y:x;

    //follower->leader
    if(!check(follower,leader)) return false;

    //path:leader->...->u
    vector<int>path;
    for(int i=u;i;i=pre[i])
        path.push_back(i);
    reverse(path.begin(),path.end());

    if(path.empty()||path[0]!=leader) return false;

    for(size_t i=1;i<path.size();i++)
        if(!check(path[i-1],path[i])) return false;

    //circle
    for(size_t i=1;i<circle.size();i++)
        if(!check(circle[i-1],circle[i])) return false;
    if(!check(circle.back(),u)) return false;
    
    //follower->leader:nxt
    if(nxt[follower]!=leader) return false;

    //check there are no circles in special_nodes
    for(int i=1;i<=m;i++)
    {
        auto &[u,v]=op[i];
        if(special_node[u]&&special_node[v])
        {
            int cnt=0;
            if(nxt[u]==v) ++cnt;
            if(nxt[v]==u) ++cnt;
            if(cnt!=1) return false;
        }
    }

    //get_ans
    for(int i=1;i<=m;i++)
    {
        auto &[u,v]=op[i];
        if(special_node[u]&&special_node[v])
        {
            if(nxt[u]==v) ans[i]={u,v};
            else ans[i]={v,u};
        }
        else if(special_node[u]&&!special_node[v]) ans[i]={v,u};
        else if(special_node[v]&&!special_node[u]) ans[i]={u,v};
        else ans[i]={u,v};
    }
    return true;
}

bool bfs()
{
    queue<int>q;
    vector<int>pre(n+1,-1),root(n+1,0);
    vector<bool>vis_edge(m+1,false);

    q.push(x),q.push(y);
    pre[x]=pre[y]=0;
    root[x]=x,root[y]=y;

    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto &[v,id]:p[u])
        {
            if(!vis_edge[id])
            {
                vis_edge[id]=true;
                vector<int> circle=find_circle(u,v,id);

                if(circle.size())
                {
                    if(get_ans(u,root,pre,circle)) return true;
                }
            }
            if(pre[v]==-1)
            {
                pre[v]=u;
                root[v]=root[u];
                q.push(v);
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m>>x>>y;clear();
    bool adjacent=false;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        op[i]={u,v};
        p[u].push_back({v,i});
        p[v].push_back({u,i});
        if((u==x&&v==y)||(u==y&&v==x)) adjacent=true;
    }

    if(adjacent)
    {
        if(m==n-1)
        {
            cout<<"No"<<endl;
            return;
        }

        bool flag=bfs();
        if(flag)
        {
            cout<<"Yes"<<endl;
            for(int i=1;i<=m;i++)
                cout<<ans[i].u<<' '<<ans[i].v<<endl;
        }
        else cout<<"No"<<endl;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            auto &[u,v]=op[i];
            if(u==x||u==y) ans[i]={v,u};
            else if(v==x||v==y) ans[i]={u,v};
            else ans[i]={u,v};
        }

        cout<<"Yes"<<endl;
        for(int i=1;i<=m;i++)
            cout<<ans[i].u<<' '<<ans[i].v<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}