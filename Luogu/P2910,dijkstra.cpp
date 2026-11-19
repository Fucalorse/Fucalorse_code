#include <bits/stdc++.h>
using namespace std;

const int MAX=1e4+90,LEN=150;

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

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
int f[LEN][LEN],op[MAX],dist[LEN];
bool vis[LEN];

int bfs(int st,int ed)
{
    priority_queue<qwq>q;
    q.push({st,0});
    memset(dist,0x3f,sizeof dist);
    memset(vis,false,sizeof vis);
    dist[st]=0;
    while(!vis[ed]&&q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=1;i<=n;i++)
        {
            if(i==cur.pos||vis[i]) continue;
            if(dist[i]>dist[cur.pos]+f[cur.pos][i])
            {
                dist[i]=dist[cur.pos]+f[cur.pos][i];
                if(!vis[i]) q.push({i,dist[i]});
            }
        }
    }
    return dist[ed];
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
        op[i]=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            f[i][j]=read();
    int total=0;
    for(int i=2;i<=m;i++)
        total+=bfs(op[i-1],op[i]);
    printf("%d\n",total);
    return 0;
}