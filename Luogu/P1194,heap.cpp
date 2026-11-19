#include <bits/stdc++.h>
using namespace std;

const int MAX=1090,LEN=3e5+90;

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
}op[LEN<<1];

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

int w,n;
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    q.push({1,w});
    int ans=0,total=n;
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        ans+=cur.val;
        if(--total==0) break;
        for(int i=head[cur.pos];i;i=op[i].next)
        {
            int &to=op[i].to;
            if(!vis[to]) q.push({to,op[i].val});
        }
    }
    printf("%d\n",ans);
}

int main()
{
    w=read(),n=read();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int a=read();
            if(i==j) continue;
            if(!a) add(i,j,w);
            else add(i,j,min(a,w));
        }
    bfs();
    return 0;
}