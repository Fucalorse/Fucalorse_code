#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90;

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
}op[MAX];

int head[MAX],cnt=1;
void add(int from,int to,int n)
{
    op[cnt]={head[from],to,n};
    head[from]=cnt;
    cnt++;
}

int t,n,m;
int dist[MAX],f[MAX];
bool vis[MAX];

void bfs()
{
    queue<int>q;
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof vis);
    memset(f,0,sizeof f);
    q.push(1);
    dist[1]=0,vis[1]=true;
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
                if(f[to]>=n)
                {
                    printf("YES\n");
                    return;
                }
                if(!vis[to])
                {
                    vis[to]=true;
                    q.push(to);
                }
            }
        }
    }
    printf("NO\n");
}

int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        memset(op,0,sizeof op),memset(head,0,sizeof head);cnt=1;
        for(int i=1;i<=m;i++)
        {
            int u=read(),v=read(),val=read();
            add(u,v,val);
            if(val>=0) add(v,u,val);
        }
        bfs();
    }
    return 0;
}