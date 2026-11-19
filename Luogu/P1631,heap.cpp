#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

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
    LL val;
    int pos,pre;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n;
LL a[MAX],b[MAX];
priority_queue<qwq>q;

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=n;i++)
    {
        b[i]=read();
        q.push({a[1]+b[i],i,1});
    }
    for(int i=1;i<=n;i++)
    {
        qwq cur=q.top();q.pop();
        printf("%lld ",cur.val);
        q.push({b[cur.pos]+a[cur.pre+1],cur.pos,cur.pre+1});
    }
    return 0;
}