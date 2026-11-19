#include <bits/stdc++.h>
using namespace std;

#define LL long long

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

int main()
{
    n=read();
    LL pre=read(),now,pos=0,neg=0;
    for(int i=1;i<n;i++)
    {
        now=read();
        if(now-pre>0) pos+=now-pre;
        else neg-=now-pre;
        pre=now;
    }
    printf("%lld\n",pos>neg?pos:neg);
    printf("%lld\n",llabs(pos-neg)+1);
    return 0;
}