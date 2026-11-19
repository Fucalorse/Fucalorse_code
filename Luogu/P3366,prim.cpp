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
}op[MAX<<7];

int head[MAX],cnt=1;
void add(int from,int to,int val)
{
    op[cnt]={head[from],to,val};
    head[from]=cnt++;
}

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    int ans=0,total=0;
    q.push({1,0});
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        ans+=cur.val;
        total++;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(!vis[to]) q.push({to,op[i].val});
        }
    }
    if(total!=n) printf("orz\n");
    else printf("%d\n",ans);
}

int main()
{
    n=read(),m=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val),add(v,u,val);
    }
    bfs();
    return 0;
}