#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e5+90;

struct qwq
{
    int pos;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int k;
LL dist[MAX];
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    memset(dist,0x3f,sizeof dist);
    for(int i=1;i<=9;i++)
    {
        dist[i%k]=min((LL)i,dist[i%k]);
        q.push({i%k,(LL)i});
    }
    while(q.size()&&!vis[0])
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pos]) continue;
        vis[cur.pos]=true;
        for(int i=0;i<=9;i++)
        {
            int to=(cur.pos*10+i)%k;
            if(dist[to]>dist[cur.pos]+i)
            {
                dist[to]=dist[cur.pos]+i;
                if(!vis[to]) q.push({to,dist[to]});
            }
        }
    }
    cout<<dist[0]<<'\n';
}

int main()
{
    cin>>k;
    bfs();
    return 0;
}