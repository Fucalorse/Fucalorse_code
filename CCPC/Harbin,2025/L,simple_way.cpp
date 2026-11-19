#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0}};

struct qwq
{
    int x,y,mask;
};

int n,m,k;

void solve()
{
    cin>>n>>m>>k;

    vector<pair<int,int>>op(m+1,pair<int,int>{});
    vector<vector<bool>>block(n+1,vector<bool>(m+1,false));
    for(int i=0;i<k;i++)
    {
        int row,col;
        cin>>row>>col;
        op[col]={row,i};
        block[row][col]=true;
    }

    int S=1<<k;
    queue<qwq>q;
    vector<vector<vector<int>>>dist(n+1,vector<vector<int>>(m+1,vector<int>(S,INF)));
    for(int i=1;i<=n;i++)
    {
        q.push({i,1,0});
        dist[i][1][0]=0;
    }
    while(q.size())
    {
        auto [x,y,pre_mask]=q.front();q.pop();
        for(const auto &[dx,dy]:h)
        {
            int nx=x+dx,ny=y+dy;
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!block[nx][ny])
            {
                int now_mask=pre_mask;
                const auto &[row,id]=op[ny];
                if(row!=0)
                {
                    if(nx>row) now_mask|=1<<id;
                }

                if(dist[nx][ny][now_mask]==INF)
                {
                    dist[nx][ny][now_mask]=dist[x][y][pre_mask]+1;
                    q.push({nx,ny,now_mask});
                }
            }
        }
    }

    // for(int i=1;i<=n;i++)
    //     cout<<dist[i][4][0]<<' ';
    // cout<<endl;

    for(int mask=0;mask<S;mask++)
    {
        int ans=INF;
        for(int i=1;i<=n;i++)
            ans=min(ans,dist[i][m][mask]);
        cout<<(ans==INF?-1:ans)<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}