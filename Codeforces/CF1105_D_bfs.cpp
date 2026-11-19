#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};

struct qwq
{
    int x,y;
};

int n,m,k;
int id[MAX][MAX],v[20],ans[20];
char op[MAX][MAX];
queue<qwq>q[20];

bool dis(const int &x,const int &y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}

void bfs()
{
    while(1)
    {
        bool f=false;
        for(int p=1;p<=k;p++)
            for(int i=1;i<=v[p];i++)
            {
                int len=q[p].size();
                if(!len) break;
                while(len--)
                {
                    auto [x,y]=q[p].front();q[p].pop();
                    for(int s=0;s<4;s++)
                    {
                        int nx=x+dx[s],ny=y+dy[s];
                        if(dis(nx,ny)&&!id[nx][ny]&&op[nx][ny]!='#')
                        {
                            f=true;
                            id[nx][ny]=p;
                            ans[p]++;
                            q[p].push({nx,ny});
                        }
                    }
                }
            }
        if(!f) break;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>op[i][j];
            if(isdigit(op[i][j]))
            {
                id[i][j]=op[i][j]-'0';
                ans[id[i][j]]++;
                q[id[i][j]].push({i,j});
            }
        }
    bfs();
    for(int i=1;i<=k;i++)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}