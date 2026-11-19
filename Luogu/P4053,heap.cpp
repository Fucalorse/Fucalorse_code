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
    LL cost,dl;
    bool operator<(const qwq &a)const { return dl<a.dl; }
};

int n;
vector<qwq>op;
priority_queue<LL>q;

int main()
{
    n=read();
    for(int i=0;i<n;i++)
        op.push_back({read(),read()});
    sort(op.begin(),op.end());
    LL total=0;
    for(auto now:op)
    {
        total+=now.cost;
        q.push(now.cost);
        while(q.size()&&total>now.dl)
        {
            total-=q.top();
            q.pop();
        }
    }
    printf("%d\n",(int)q.size());
    return 0;
}