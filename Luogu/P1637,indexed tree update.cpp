#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5;

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
    int op[MAX+90];
    int lowbit(int n) { return n&-n; }
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
}f,g;

int main()
{
    int n=read();
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        int a=read();
        total+=g.query(a-1);
        g.update(a,f.query(a-1));
        f.update(a,1);
    }
    printf("%lld\n",total);
    return 0;
}