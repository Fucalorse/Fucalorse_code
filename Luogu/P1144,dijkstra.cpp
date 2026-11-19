#include <bits/stdc++.h>
using namespace std;

const int MAX=1e6+90,mod=1e5+3;

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
int f[MAX],dist[MAX];
bool vis[MAX];
vector<int>p[MAX];
priority_queue<qwq>q;

void bfs()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0,f[1]=1;
    q.push({1,0});
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(auto &to:p[cur.pos])
        {
            if(vis[to]) continue;
            if(dist[to]>dist[cur.pos]+1)
            {
                dist[to]=dist[cur.pos]+1;
                f[to]=f[cur.pos]%mod;
                if(!vis[to]) q.push({to,dist[to]});
            }
            else if(dist[to]==dist[cur.pos]+1) f[to]=(f[to]+f[cur.pos])%mod;
        }
    }
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        p[u].push_back(v),p[v].push_back(u);
    }
    bfs();
    for(int i=1;i<=n;i++)
        printf("%d\n",f[i]);
    return 0;
}