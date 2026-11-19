#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=60,LEN=50;

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

int n;
LL f[MAX];

void update(LL x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                break;
            }
            else x^=f[i];
        }
}

LL query()
{
    LL ans=0;
    for(int i=LEN;i>=0;i--)
        if((ans^f[i])>ans) ans^=f[i];
    return ans;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        LL x=read();
        update(x);
    }
    printf("%lld\n",query());
    return 0;
}