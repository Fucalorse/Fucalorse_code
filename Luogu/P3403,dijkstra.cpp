#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long

const int MAX=1e5+90;

ULL read()
{
    ULL ans=0,f=1;
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
    int next,to;
    ULL val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,ULL val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt++;
}

struct qwq
{
    int pos;
    ULL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

ULL h;
int x,y,z;
ULL dist[MAX];
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    memset(dist,0x3f,sizeof dist);
    dist[0]=0;
    q.push({0,0});
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(dist[to]>dist[cur.pos]+op[i].val)
            {
                dist[to]=dist[cur.pos]+op[i].val;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
}

int main()
{
    h=read(),x=read(),y=read(),z=read();
    if(x==1||y==1||z==1)
    {
        printf("%llu\n",h);
        exit(0);
    }
    for(int i=0;i<x;i++)
    {
        if((i+y)%x!=i) add(i,(i+y)%x,(ULL)y);
        if((i+z)%x!=i) add(i,(i+z)%x,(ULL)z);
    }
    bfs();
    ULL total=0;
    --h;
    for(int i=0;i<x;i++)
        if(h>=dist[i]) total+=(h-dist[i])/x+1;
    printf("%llu\n",total);
    return 0;
}