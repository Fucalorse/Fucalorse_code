#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90;

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
    int to,next,val;
}op[MAX<<1];

int head[MAX],cnt=1;
void add(const int &from,const int &to,const int &n)
{
    op[cnt].to=to;
    op[cnt].next=head[from];
    op[cnt].val=n;
    head[from]=cnt;
    cnt++;
}

int n;
int f[MAX];
LL ans=0;

int dfs(int ch,int fa)
{
    f[ch]=1;
    for(int i=head[ch];i;i=op[i].next)
        if(op[i].to!=fa)
        {
            f[ch]+=dfs(op[i].to,ch);
            ans+=(LL)op[i].val*abs(2*f[op[i].to]-n);
        }
    return f[ch];
}

int main()
{
    n=read();
    for(int i=1;i<n;i++)
    {
        int u=read(),v=read(),val=read();
        add(u,v,val);
        add(v,u,val);
    }
    dfs(1,0);
    printf("%lld\n",ans);
    return 0;
}