#include <bits/stdc++.h>
using namespace std;

const int MAX=150;
const int dx[8]={-1,-1,-1,0,1,1,1,0};
const int dy[8]={-1,0,1,1,1,0,-1,-1};

struct qwq
{
    int x,y,t;
}st;

int h,w;
char op[MAX][MAX];
bool vis[MAX][MAX]={false};
queue<qwq>q;

bool dis(const int &i,const int &j)
{
    return i>=1&&i<=h&&j>=1&&j<=w&&op[i][j]!='*';
}

void bfs()
{
    q.push(st);
    vis[st.x][st.y]=true;
    int ans=0;
    while(q.size())
    {
        qwq cur=q.front();q.pop();
        ans=max(ans,cur.t);
        for(int s=0;s<8;s++)
        {
            int nx=cur.x+dx[s],ny=cur.y+dy[s];
            if(dis(nx,ny)&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                q.push({nx,ny,cur.t+1});
            }
        }
    }
    printf("%d\n",ans);
}

int main()
{
    cin>>w>>h>>st.y>>st.x;
    st.t=0;
    for(int i=h;i>=1;i--)
        for(int j=1;j<=w;j++)
            cin>>op[i][j];
    bfs();
    return 0;
}