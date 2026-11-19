#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,inf=2e9;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct ovo
{
    int maxn,minn;
}num[MAX];

stack<int>st;
bool vis[MAX],reach[MAX];
int n,m;
int dfn[MAX],low[MAX],comb[MAX],indeg[MAX],pre[MAX],f[MAX],qwq=0,scc=1;
vector<int>p[MAX],np[MAX],op[MAX];

void dfs(int u)
{
    dfn[u]=low[u]=++qwq;
    st.push(u);
    vis[u]=true;
    for(auto &v:p[u])
    {
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        num[scc]={0,inf};
        while(1)
        {
            int v=st.top();st.pop();
            vis[v]=false;
            comb[v]=scc;
            num[scc].maxn=max(num[scc].maxn,pre[v]);
            num[scc].minn=min(num[scc].minn,pre[v]);
            if(v==u) break;
        }
        scc++;
    }
}

void bfs()
{
    queue<int>q;
    reach[comb[n]]=true;
    for(int i=1;i<=scc;i++)
        if(indeg[i]==0)
        {
            q.push(i);
            f[i]=num[i].maxn;
        }
    while(q.size())
    {
        int cur=q.front();q.pop();
        for(auto &to:np[cur])
        {
            reach[to]|=reach[cur];
            if(reach[to]) f[to]=max(f[to],max(num[to].maxn,f[cur]));
            if(--indeg[to]==0) q.push(to);
        }
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        pre[i]=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),pos=read();
        p[u].push_back(v);
        if(pos==2) p[v].push_back(u);
    }
    dfs(1);
    for(int u=1;u<=n;u++)
        for(auto &v:p[u])
        {
            if(comb[u]!=comb[v]&&comb[u]&&comb[v])
            {
                np[comb[v]].push_back(comb[u]);
                indeg[comb[u]]++;
            }
        }
    bfs();
    int ans=0;
    for(int i=1;i<=scc;i++)
        if(reach[i]) ans=max(ans,f[i]-num[i].minn);
    printf("%d\n",ans);
    return 0;
}