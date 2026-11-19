#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5,LEN=3e4+90;

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

struct fucalorse
{
    LL op[MAX+90];
    int lowbit(int n) { return n&-n; }
    void update(int n,const int &k)
    {
        while(n<=MAX)
        {
            op[n]+=k;
            n+=lowbit(n);
        }
    }
    LL query(int n)
    {
        LL ans=0;
        while(n)
        {
            ans+=op[n];
            n-=lowbit(n);
        }
        return ans;
    }
}fu,fufu;

int n;
int f[LEN],op[LEN];

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        op[i]=read();
        f[i]=fu.query(op[i]-1);
        fu.update(op[i],1);
    }
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        total+=fufu.query(op[i]-1);
        fufu.update(op[i],f[i]);
    }
    printf("%lld\n",total);
    return 0;
}