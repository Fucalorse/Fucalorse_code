#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1090,LEN=60;

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

struct qwq
{
    LL id,val;
    bool operator<(const qwq &a)const { return val>a.val; }
}op[MAX];

int n;
LL f[MAX];

bool update(LL x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return true;
            }
            else x^=f[i];
        }
    return false;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        op[i]={read(),read()};
    sort(op+1,op+n+1);
    LL ans=0;
    for(int i=1;i<=n;i++)
        if(update(op[i].id)) ans+=op[i].val;
    printf("%lld\n",ans);
    return 0;
}