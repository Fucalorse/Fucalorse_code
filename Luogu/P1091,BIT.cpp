#include <bits/stdc++.h>
using namespace std;

const int MAX=250;

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

struct peach
{
    private:
        int op[MAX+90];
        int lowbit(int n) { return n&-n; }
    public:
        void update(int n,const int &k)
        {
            while(n<=MAX)
            {
                op[n]+=k;
                n+=lowbit(n);
            }
        }
        int query(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=op[n];
                n-=lowbit(n);
            }
            return ans;
        }
}fu,fufu;

int n;
int num[MAX],f[MAX],g[MAX],op[MAX],qwq=0;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        num[i]=read();
    for(int i=1;i<=n;i++)
    {
        int pos=fu.query(num[i]-1)+1;
        if(pos<=qwq) fu.update(op[pos],-1);
        fu.update(num[i],1);
        op[pos]=num[i];
        f[i]=pos;
        qwq=max(qwq,pos);
    }
    memset(op,0,sizeof op),qwq=0;
    for(int i=n;i>=1;i--)
    {
        int pos=fufu.query(num[i]-1)+1;
        if(pos<=qwq) fufu.update(op[pos],-1);
        fufu.update(num[i],1);
        op[pos]=num[i];
        g[i]=pos;
        qwq=max(qwq,pos);
    }
    int ans=1;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i]+g[i]-1);
    printf("%d\n",n-ans);
    return 0;
}