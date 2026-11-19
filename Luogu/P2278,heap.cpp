#include <bits/stdc++.h>
using namespace std;

struct qwq
{
    int id,cost,k;
    bool operator<(const qwq &a)const
    {
        if(k!=a.k) return k<a.k;
        return id>a.id;
    }
};

priority_queue<qwq>q;

int main()
{
    int id,st,c,k;
    scanf("%d%d%d%d",&id,&st,&c,&k);
    q.push({id,c,k});
    int now=st;
    while(scanf("%d%d%d%d",&id,&st,&c,&k)==4)
    {
        while(q.size())
        {
            qwq cur=q.top();q.pop();
            if(now+cur.cost<=st)
            {
                now+=cur.cost;
                printf("%d %d\n",cur.id,now);
            }
            else
            {
                cur.cost-=st-now;
                q.push(cur);
                now=st;
                break;
            }
        }
        if(now<st) now=st;
        q.push({id,c,k});
    }
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        now+=cur.cost;
        printf("%d %d\n",cur.id,now);
    }
    return 0;
}