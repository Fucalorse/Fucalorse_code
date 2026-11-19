#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

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

stack<int>st;
bool vis[MAX];
int n,m;
int dfn[MAX],low[MAX],indeg[MAX],comb[MAX],f[MAX],cnt[MAX],qwq=0,scc=1;
vector<pair<int,int>>p[MAX],np[MAX];
queue<int>q;

void dfs(int u)
{
    dfn[u]=low[u]=++qwq;
    st.push(u);
    vis[u]=true;
    for(auto &i:p[u])
    {
        int v=i.first;
        if(!dfn[v])
        {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        while(1)
        {
            int v=st.top();st.pop();
            vis[v]=false;
            comb[v]=scc;
            cnt[scc]++;
            if(u==v) break;
        }
        scc++;
    }
}

bool dis()
{
    for(int u=1;u<=n;u++)
        for(auto &i:p[u])
        {
            int v=i.first,val=i.second;
            if(comb[u]==comb[v]&&val) return false;
        }
    return true;
}

void bfs()
{
    for(int i=1;i<=scc;i++)
        if(indeg[i]==0)
        {
            q.push(i);
            f[i]=1;
        }
    while(q.size())
    {
        int cur=q.front();q.pop();
        for(auto &i:np[cur])
        {
            int to=i.first,val=i.second;
            f[to]=max(f[to],f[cur]+val);
            if(--indeg[to]==0) q.push(to);
        }
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int pos=read(),u=read(),v=read();
        if(pos==1) p[u].push_back({v,0}),p[v].push_back({u,0});
        else if(pos==2) p[u].push_back({v,1});
        else if(pos==3) p[v].push_back({u,0});
        else if(pos==4) p[v].push_back({u,1});
        else p[u].push_back({v,0});
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i]) dfs(i);
    if(!dis())
    {
        printf("-1\n");
        exit(0);
    }
    for(int u=1;u<=n;u++)
        for(auto &i:p[u])
        {
            int v=i.first,val=i.second;
            if(comb[u]!=comb[v])
            {
                np[comb[u]].push_back({comb[v],val});
                indeg[comb[v]]++;
            }
        }
    bfs();
    LL total=0;
    for(int i=1;i<=scc;i++)
        total+=(LL)f[i]*cnt[i];
    printf("%lld\n",total);
    return 0;
}