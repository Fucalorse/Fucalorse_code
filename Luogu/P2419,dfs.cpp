#include <bits/stdc++.h>
using namespace std;

const int MAX=150;

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

int n,m;
bool vis[MAX];
vector<int>pw[MAX],pl[MAX];

int dfs(int pos,vector<int>(&p)[MAX])
{
    if(vis[pos]) return 0;
    vis[pos]=true;
    int cnt=0;
    for(auto &to:p[pos])
        if(!vis[to]) cnt+=dfs(to,p);
    return cnt+1;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        pw[u].push_back(v);
        pl[v].push_back(u);
    }
    int total=0;
    for(int i=1;i<=n;i++)
    {
        memset(vis,false,sizeof vis);
        int now=dfs(i,pw);
        memset(vis,false,sizeof vis);
        now+=dfs(i,pl)-1;
        if(now==n) total++;
    }
    printf("%d\n",total);
    return 0;
}