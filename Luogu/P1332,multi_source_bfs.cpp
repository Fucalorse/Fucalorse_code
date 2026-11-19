#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=550,inf=2e9;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y;
}op[MAX];

int n,m,a,b;
int dist[LEN][LEN];
bool vis[LEN][LEN];
queue<qwq>q;

bool dis(const int &x,const int &y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}

void bfs()
{
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        for(int s=0;s<4;s++)
        {
            int nx=x+dx[s],ny=y+dy[s];
            if(dis(nx,ny)&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>a>>b;
    for(int i=1;i<=a;i++)
    {
        int x,y;
        cin>>x>>y;
        vis[x][y]=true;
        q.push({x,y});
    }
    for(int i=1;i<=b;i++)
        cin>>op[i].x>>op[i].y;
    bfs();
    for(int i=1;i<=b;i++)
    {
        auto &[x,y]=op[i];
        cout<<dist[x][y]<<'\n';
    }
    return 0;
}