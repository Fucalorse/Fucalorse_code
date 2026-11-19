#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

LL read()
{
    LL ans=0,f=1;
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
    LL val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(int from,int to,LL val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt++;
}

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val;}
};

int n,m;
LL k;
bool vis[MAX];
LL cost[MAX],num[MAX];

LL bfs(const LL &mid)
{
    if(num[1]>mid||num[n]>mid) return 1e18;
    memset(vis,false,sizeof vis);
    memset(cost,0x3f,sizeof cost);
    priority_queue<qwq>q;
    q.push({1,0});
    cost[1]=0;
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(num[to]>mid) continue;
            if(cost[to]>cost[cur.pos]+op[i].val)
            {
                cost[to]=cost[cur.pos]+op[i].val;
                if(!vis[to]) q.push({to,cost[to]});
            }
        }
    }
    return cost[n];
}

int main()
{
    n=read(),m=read(),k=read();
    LL l=2e9,r=0;
    for(int i=1;i<=n;i++)
    {
        num[i]=read();
        if(num[i]<l) l=num[i];
        if(num[i]>r) r=num[i];
    }
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read();
        LL val=read();
        add(u,v,val),add(v,u,val);
    }
    bool f=false;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        LL now=bfs(mid);
        if(now<=k) r=mid-1,f=true;
        else l=mid+1;
    }
    if(f) printf("%lld\n",l);
    else printf("AFK");
    return 0;
}