#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=30;

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
void add(int from,int to,int n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

struct qwq
{
    qwq *op[2];
    qwq() { op[0]=op[1]=nullptr; }
};

int n;
int f[MAX];

struct fucalorse
{
    qwq *root=new qwq;
    void update(const int &sum)
    {
        qwq *now=root;
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1;
            if(!now->op[p]) now->op[p]=new qwq;
            now=now->op[p];
        }
    }
    int query(const int &sum)
    {
        qwq *now=root;
        int ans=0;
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1;
            if(!now->op[p^1]) now=now->op[p];
            else
            {
                ans+=1<<i;
                now=now->op[p^1];
            }
        }
        return ans;
    }
    void dfs(int p,int fa)
    {
        for(int i=head[p];i;i=op[i].next)
            if(op[i].to!=fa)
            {
                f[op[i].to]=f[p]^op[i].val;
                dfs(op[i].to,p);
            }
    }
}fu;

int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val);
        add(v,u,val);
    }
    fu.dfs(1,-1);
    for(int i=1;i<=n;i++)
        fu.update(f[i]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,fu.query(f[i]));
    printf("%d\n",ans);
    return 0;
}