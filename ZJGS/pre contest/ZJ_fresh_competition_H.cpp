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

int n,m;
priority_queue<LL>q;

int main()
{
    n=read(),m=read();
    for(int i=1;i<n;i++)
    {
        int x=read();
        LL val=read();
        q.push(val);
    }
    for(int i=1;i<=m;i++)
    {
        LL now=q.top();q.pop();
        q.push(now/2);
    }
    LL ans=0;
    while(q.size())
    {
        LL cur=q.top();q.pop();
        ans+=cur;
    }
    printf("%lld\n",ans);
    return 0;
}