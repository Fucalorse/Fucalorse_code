#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=2090;
const vector<pair<int,int>>h={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int t,n,m;
int a[MAX][MAX];
bool vis[MAX][MAX];

bool dis(const int &i,const int &j) { return i>=1&&i<=n&&j>=1&&j<=m; }

bool bfs(const int &i,const int &j)
{
    queue<pair<int,int>>q;
    vector<pair<int,int>>point;
    vis[i][j]=true,point.emplace_back(i,j);
    q.push({i,j});
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        if(x==n||y==1)
        {
            for(auto &[i,j]:point)
                vis[i][j]=false;
            return true;
        }
        for(auto &[dx,dy]:h)
        {
            int nx=x+dx,ny=y+dy;
            if(dis(nx,ny)&&!vis[nx][ny]&&a[x][y]==a[nx][ny])
            {
                vis[nx][ny]=true;
                point.emplace_back(nx,ny);
                q.push({nx,ny});
            }
        }
    }
    for(auto &[i,j]:point)
        vis[i][j]=false;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        unordered_set<int>st;
        for(int j=1;j<=m;j++)
            if(bfs(1,j)) st.insert(a[1][j]);
        for(int i=1;i<=n;i++)
            if(bfs(i,m)) st.insert(a[i][m]);
        for(int ans=0;;++ans)
            if(!st.count(ans))
            {
                cout<<ans<<endl;
                break;
            }
    }
    return 0;
}