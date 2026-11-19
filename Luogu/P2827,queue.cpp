#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int inf=1e9;

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

int n,m,t;
LL u,v,q;
queue<LL>a,b,c;
vector<LL>op;

int main()
{
    n=read(),m=read(),q=read(),u=read(),v=read(),t=read();
    for(int i=0;i<n;i++)
        op.push_back(read());
    sort(op.begin(),op.end(),greater<LL>());
    for(auto i:op)
        a.push(i);
    for(int i=1;i<=m;i++)
    {
        LL x=a.empty()?-inf:a.front()+q*(i-1);
        LL y=b.empty()?-inf:b.front()+q*(i-1);
        LL z=c.empty()?-inf:c.front()+q*(i-1);
        LL aft;
        if(x>=y&&x>=z) aft=x,a.pop();
        else if(y>=x&&y>=z) aft=y,b.pop();
        else aft=z,c.pop();
        LL now=aft*u/v;
        b.push(now-i*q),c.push(aft-now-i*q);
        if(i%t==0) printf("%lld ",aft);
    }
    printf("\n");
    for(int i=1;i<=n+m;i++)
    {
        LL x=a.empty()?-inf:a.front()+q*m;
        LL y=b.empty()?-inf:b.front()+q*m;
        LL z=c.empty()?-inf:c.front()+q*m;
        LL aft;
        if(x>=y&&x>=z) aft=x,a.pop();
        else if(y>=x&&y>=z) aft=y,b.pop();
        else aft=z,c.pop();
        if(i%t==0) printf("%lld ",aft);
    }
    return 0;
}