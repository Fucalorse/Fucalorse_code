#include <bits/stdc++.h>
using namespace std;

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

int n,k;
int f[MAX],deg[MAX];
vector<int>p[MAX];
queue<int>q;

void bfs()
{
    for(int i=1;i<=n;i++)
        if(deg[i]==1) q.push(i);
    int ans=0,rest=n;
    while(rest>k)
    {
        int cur=q.front();q.pop();
        rest--;
        for(auto to:p[cur])
        {
            f[to]=f[cur]+1;
            ans=max(ans,f[to]);
            if(--deg[to]==1) q.push(to);
        }
    }
    printf("%d\n",ans);
}

int main()
{
    n=read(),k=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v);
        p[v].push_back(u);
        deg[u]++,deg[v]++;
    }
    bfs();
    return 0;
}