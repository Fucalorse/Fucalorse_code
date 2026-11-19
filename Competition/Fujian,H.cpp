#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090,inf=0x3f3f3f3f;
const vector<pair<int,int>>h={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

struct qwq
{
    int x,y,t;
};

int t,n,m,l,r;
char s[MAX][MAX];

bool dis(const int &x,const int &y)
{
    return x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='1';
}

pair<int,int> bfs()
{
    vector<vector<array<int,2>>>dist(n+3,vector<array<int,2>>(m+3,{inf,inf}));
    queue<qwq>q;
    q.push({1,1,0});
    dist[1][1][0]=0;
    while(q.size())
    {
        auto [x,y,p]=q.front();q.pop();
        for(auto &[dx,dy]:h)
        {
            int nx=x+dx,ny=y+dy;
            if(dis(nx,ny)&&dist[nx][ny][p^1]>dist[x][y][p]+1)
            {
                dist[nx][ny][p^1]=dist[x][y][p]+1;
                q.push({nx,ny,p^1});
            }
        }
    }
    return {dist[n][m][1],dist[n][m][0]};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>r;
        for(int i=1;i<=n;i++)
            cin>>(s[i]+1);
        auto [odd,even]=bfs();
        if(odd==inf&&even==inf)
        {
            cout<<-1<<endl;
            continue;
        }
        int minn=min(odd,even);
        if(r>l||minn%r==0) cout<<(minn-1)/r+1<<endl;
        else
        {
            if(minn%l==0)
            {
                cout<<minn/l<<endl;
                continue;
            }
            if(l&1)
            {
                int ans=inf;
                if(odd!=inf)
                {
                    int now=(odd-1)/l+1;
                    if(now%2==0) ++now;
                    ans=min(ans,now);
                }
                if(even!=inf)
                {
                    int now=(even-1)/l+1;
                    if(now&1) ++now;
                    ans=min(ans,now);
                }
                cout<<(ans==inf?-1:ans)<<endl;
            }
            else
            {
                if(even!=inf) cout<<(even-1)/l+1<<endl;
                else cout<<-1<<endl;
            }
        }
    }
    return 0;
}