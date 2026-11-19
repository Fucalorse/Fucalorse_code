#include <bits/stdc++.h>
using namespace std;

const int MAX=3e5+90;

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
}op[MAX<<4];

int head[MAX],cnt=1;
void add(int from,int to,int val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt++;
}

int n,m;
int f[MAX],num[MAX];
bool vis[MAX];
queue<int>q;

void bfs()
{
    memset(f,0x3f,sizeof f);
    f[1]=0,vis[1]=true;
    q.push(1);
    while(q.size())
    {
        int cur=q.front();q.pop();
        vis[cur]=false;
        for(int i=head[cur];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(f[to]>f[cur]+op[i].val)
            {
                f[to]=f[cur]+op[i].val;
                if(!vis[to]) q.push(to);
            }
        }
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        num[i]=read();
        add(i,i+n,num[i]),add(i+n,i+n*2,-num[i]);
    }
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),p=read();
        add(u,v,0),add(u+n,v+n,0),add(u+2*n,v+2*n,0);
        if(p==2) add(v,u,0),add(v+n,u+n,0),add(v+2*n,u+2*n,0);
    }
    bfs();
    printf("%d\n",-f[3*n]);
    return 0;
}