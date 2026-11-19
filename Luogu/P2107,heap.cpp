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
    LL x,t;
    bool operator<(const qwq &a)const { return x<a.x; }
};

int n;
LL m;
vector<qwq>op;
priority_queue<LL>q;

int main()
{
    n=read(),m=read();
    for(int i=0;i<n;i++)
        op.push_back({read(),read()});
    sort(op.begin(),op.end());
    int ans=0;
    LL total=0;
    for(auto now:op)
    {
        total+=now.t;
        q.push(now.t);
        while(q.size()&&total+now.x>m)
        {
            total-=q.top();
            q.pop();
        }
        if(total+now.x>m&&q.empty()) break;
        ans=max(ans,(int)q.size());
    }
    printf("%d\n",ans);
    return 0;
}