#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090,inf=2e9;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0},{0,-1}};

int t,n,m;
char op[MAX][MAX];

int cal(const pair<int,int> &a,const pair<int,int> &b)
{
    return abs(a.first-b.first)+abs(a.second-b.second)+1;
}

bool dis(const int &i,const int &j) { return i>=1&&i<=n&&j>=1&&j<=m; }

bool bfs(const int &i,const int &j,vector<pair<int,int>>&obstacle)
{
    queue<pair<int,int>>q;
    vector<vector<bool>>vis(n+3,vector<bool>(m+3,false));
    q.push({i,j});
    vis[i][j]=true;
    while(q.size())
    {
        auto [x,y]=q.front();q.pop();
        if(x==n&&y==m&&i!=x&&j!=y) return true;
        // cout<<x<<' '<<y<<endl;
        for(auto &[dx,dy]:h)
        {
            int nx=x+dx,ny=y+dy;
            if(dis(nx,ny)&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                if(op[nx][ny]=='#') obstacle.push_back({nx,ny});
                else q.push({nx,ny});
            }
        }
    }
    return false;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>op[i][j];
    vector<pair<int,int>>st,ed;
    bool f=bfs(1,1,st);
    if(f)
    {
        cout<<0<<endl;
        return;
    }
    bfs(n,m,ed);
    int ans=inf;
    // for(auto &[x,y]:st)
    //     cout<<x<<' '<<y<<endl;
    for(auto &i:st)
        for(auto &j:ed)
            ans=min(ans,cal(i,j));
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}