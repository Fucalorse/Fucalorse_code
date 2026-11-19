#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+90;

struct qwq
{
    int pos,val;
    bool operator<(const qwq &a)const { return val>a.val; }
};

int n,m;
int dist[MAX];
bool vis[MAX];
priority_queue<qwq>q;

void bfs()
{
    memset(dist,0x3f,sizeof(dist));
    dist[n]=0;
    q.push({n,0});
    while(q.size())
    {
        auto [val,t]=q.top();q.pop();
        if(vis[val]) continue;
        vis[val]=true;
        if(val==m)
        {
            cout<<t<<endl;
            break;
        }
        if(val*2<m*2&&dist[val*2]>dist[val]+1)
        {
            dist[val*2]=dist[val]+1;
            if(!vis[val*2]) q.push({val*2,dist[val]+1});
        }
        if(val-1>0&&dist[val-1]>dist[val]+1)
        {
            dist[val-1]=dist[val]+1;
            if(!vis[val-1]) q.push({val-1,dist[val]+1});
        }
    }
}

int main()
{
    cin>>n>>m;
    bfs();
    return 0;
}