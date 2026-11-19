#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90,inf=2e9;

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
    int id,pos;
    LL rest;
    bool operator<(const qwq &a)const { return id>a.id; }
};

int t,n,m;
int pos[MAX];
LL num[MAX],x[MAX];
queue<int>q[MAX];
priority_queue<qwq>f,g;

void initial()
{
    for(int i=1;i<=n;i++)
        while(q[i].size()) q[i].pop();
    while(f.size()) f.pop();
    while(g.size()) g.pop();
}

int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        initial();
        for(int i=1;i<=n;i++)
            num[i]=read();
        for(int i=1;i<=m;i++)
        {
            x[i]=read(),pos[i]=read();
            q[pos[i]].push(i);
        }
        for(int i=1;i<=n;i++)
        {
            q[i].push(inf);
            int cur=q[i].front();q[i].pop();
            f.push({cur,i,num[i]});
        }
        LL now=0;
        for(int i=1;i<=m;i++)
        {
            while(f.size()&&now<x[i])
            {
                qwq cur=f.top();f.pop();
                if(now+cur.rest>x[i])
                {
                    cur.rest-=x[i]-now;
                    now=x[i];
                    f.push(cur);
                }
                else
                {
                    now+=cur.rest;
                    cur.rest=0;
                    g.push(cur);
                }
            }
            // cout<<f.size()<<' '<<g.size()<<endl;
            if(now<x[i]) break;
            if(f.size())
            {
                qwq cur=f.top();f.pop();
                if(cur.pos==pos[i]&&q[pos[i]].size())
                {
                    int aft=q[pos[i]].front();q[pos[i]].pop();
                    f.push({aft,pos[i],num[pos[i]]});
                    continue;
                }
                f.push(cur);
            }
            if(g.size())
            {
                qwq cur=g.top();g.pop();
                if(cur.pos==pos[i]&&q[pos[i]].size())
                {
                    int aft=q[pos[i]].front();q[pos[i]].pop();
                    f.push({aft,pos[i],num[pos[i]]});
                    continue;
                }
                g.push(cur);
            }
        }
        while(f.size())
        {
            qwq cur=f.top();f.pop();
            // cout<<cur.rest<<endl;
            now+=cur.rest;
        }
        printf("%lld\n",now);
    }
    return 0;
}