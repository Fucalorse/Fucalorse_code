#include <bits/stdc++.h>
using namespace std;

const int MAX=5090;

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

struct edge
{
    int next,to,val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,int val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt;
    cnt++;
}

int n,m;
int dist[MAX],f[MAX];
bool vis[MAX];
queue<int>q;

bool bfs()
{
    q.push(0);
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    vis[0]=true;
    while(q.size())
    {
        int cur=q.front();q.pop();
        vis[cur]=false;
        for(int i=head[cur];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(dist[cur]+op[i].val<dist[to])
            {
                dist[to]=dist[cur]+op[i].val;
                f[to]=f[cur]+1;
                if(f[to]>=n+1) return false;
                if(!vis[to])
                {
                    vis[to]=true;
                    q.push(to);
                }
            }
        }
    }
    return true;
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(v,u,val);
    }
    for(int i=1;i<=n;i++)
        add(0,i,0);
    if(bfs())
    {
        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);
        printf("\n");
    }
    else printf("NO\n");
    return 0;
}