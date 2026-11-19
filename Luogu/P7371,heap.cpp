#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90;

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
    LL w,h;
    bool operator<(const qwq &a)const { return h<a.h; }
}op[MAX];

int n,k;
priority_queue<LL>q;

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        op[i]={read(),read()};
    sort(op+1,op+n+1);
    LL w=0,h=0;
    for(int i=1;i<=k;i++)
    {
        q.push(op[i].w);
        w+=op[i].w;
        h=max(h,op[i].h);
    }
    LL ans=w*h;
    for(int i=k+1;i<=n;i++)
    {
        LL cur=q.top();q.pop();
        w=w-cur+op[i].w;
        h=op[i].h;
        q.push(op[i].w);
        ans=min(ans,w*h);
    }
    printf("%lld\n",ans);
    return 0;
}