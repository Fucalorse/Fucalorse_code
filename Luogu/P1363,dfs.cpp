#include <bits/stdc++.h>
using namespace std;

const int MAX=1590;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y;
}op[MAX][MAX],st;

int n,m;
char str[MAX][MAX];
bool vis[MAX][MAX];

bool dfs(int i,int j,int pi,int pj)
{
    if(vis[i][j]&&(op[i][j].x!=pi||op[i][j].y!=pj)) return true;
    vis[i][j]=true,op[i][j]={pi,pj};
    for(int s=0;s<4;s++)
    {
        int ni=(i+dx[s]+n)%n,nj=(j+dy[s]+m)%m;
        if(str[ni][nj]=='#') continue;
        int li=pi+dx[s],lj=pj+dy[s];
        if(!vis[ni][nj]||op[ni][nj].x!=li||op[ni][nj].y!=lj) 
        {
            if(dfs(ni,nj,li,lj)) return true;
        }
    }
    return false;
}

int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                cin>>str[i][j];
                if(str[i][j]=='S') st={i,j};
            }
        memset(vis,false,sizeof vis);
        memset(op,0,sizeof op);
        if(dfs(st.x,st.y,st.x,st.y)) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}