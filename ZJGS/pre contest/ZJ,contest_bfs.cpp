#include <bits/stdc++.h>
using namespace std;

const int MAX=510,inf=0x3f3f3f3f;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y,t;
};

int n,m,tot=0;
int minn[110],op[MAX][MAX],cnt[MAX][MAX];
bool vis[MAX][MAX];
vector<qwq>passer,band;

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=n&&j>=1&&j<=m;
}

void bfs()
{
    memset(minn,0x3f,sizeof minn);
    memset(vis,false,sizeof vis);
    queue<qwq>q;
    for(auto &i:band)
    {
        vis[i.x][i.y]=true;
        q.push(i);
    }
    while(q.size())
    {
        qwq cur=q.front();q.pop();
        int x=cur.x,y=cur.y;
        if(op[x][y]>0) minn[op[x][y]]=min(minn[op[x][y]],cur.t);
        for(int s=0;s<4;s++)
        {
            int nx=x+dx[s],ny=y+dy[s];
            if(dis(nx,ny)&&op[nx][ny]!=-10086&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                q.push({nx,ny,cur.t+1});
            }
        }
    }
}

void find(const qwq &st,const int &id)
{
    memset(vis,false,sizeof vis);
    vis[st.x][st.y]=true;
    queue<qwq>q;
    q.push(st);
    while(q.size())
    {
        qwq cur=q.front();q.pop();
        if(cur.t<=minn[id]) cnt[cur.x][cur.y]++;
        if(cur.t>minn[id]) continue;
        for(int s=0;s<4;s++)
        {
            int nx=cur.x+dx[s],ny=cur.y+dy[s];
            if(dis(nx,ny)&&op[nx][ny]!=-10086&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                q.push({nx,ny,cur.t+1});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c;
            cin>>c;
            if(c=='1') passer.push_back({i,j,0}),op[i][j]=++tot;
            else if(c=='p') band.push_back({i,j,0}),op[i][j]=-1;
            else if(c=='x') op[i][j]=-10086;
        }
    bfs();
    for(auto &i:passer)
        find(i,op[i.x][i.y]);
    int maxn=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(op[i][j]==-10086||op[i][j]==-1) continue;
            maxn=max(maxn,cnt[i][j]);
        }
    cout<<maxn;
    return 0;
}