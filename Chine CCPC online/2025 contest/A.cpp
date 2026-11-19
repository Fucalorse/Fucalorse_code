#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,MOD=1e9+7,LEN=5e5;

int n,m;

pair<pair<int,int>,pair<int,int>> get(pair<int,int> x)
{
    int x1=0,x2=x.first,x3=x.first-x.second,x4=-x.second;
    int y1=0,y2=x.second,y3=x.first+x.second,y4=x.first;

    pair<int,int>X={min({x1,x2,x3,x4}),max({x1,x2,x3,x4})};
    pair<int,int>Y={min({y1,y2,y3,y4}),max({y1,y2,y3,y4})};

    return {X,Y};
}

void solve()
{
    cin>>n>>m;

    int k=min(n,m);
    vector<vector<LL>>f(n+5,vector<LL>(m+5,0));
    for(int i=-k;i<=k;i++)
        for(int j=-k;j<=k;j++)
        {
            if(i==0&&j==0) continue;

            pair<int,int>now={i,j};
            auto [X,Y]=get(now);

            auto [Lx,Rx]=X;
            auto [Ly,Ry]=Y;

            // cout<<-Lx<<' '<<n-Rx<<endl;
            // cout<<-Ly<<' '<<m-Ry<<endl;

            if(-Lx<=n-Rx&&-Ly<=m-Ry)
            {
                f[-Lx][-Ly]++;
                f[n-Rx+1][m-Ry+1]++;
                f[-Lx][m-Ry+1]--;
                f[n-Rx+1][-Ly]--;
            }
        }

    // for(int i=0;i<=n+1;i++)
    // {
    //     for(int j=0;j<=m+1;j++)
    //         cout<<f[i][j]<<' ';
    //     cout<<endl;
    // }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i-1>=0) f[i][j]+=f[i-1][j];
            if(j-1>=0) f[i][j]+=f[i][j-1];
            if(i-1>=0&&j-1>=0) f[i][j]-=f[i-1][j-1];

            cout<<f[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}