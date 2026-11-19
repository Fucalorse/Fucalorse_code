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

struct qwq
{
    LL val,h;
    bool operator<(const qwq &a)const
    {
        if(val!=a.val) return val>a.val;
        return h>a.h;
    }
};

int n,k;
priority_queue<qwq>q;

int main()
{
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        q.push({read(),1});
    while((q.size()-1)%(k-1)!=0) q.push({0,1});
    LL ans=0;
    while(q.size()>=k)
    {
        LL total=0,h=0;
        for(int i=0;i<k;i++)
        {
            qwq cur=q.top();q.pop();
            total+=cur.val;
            h=max(h,cur.h);
        }
        ans+=total;
        q.push({total,h+1});
    }
    cout<<ans<<'\n'<<q.top().h-1<<'\n';
    return 0;
}