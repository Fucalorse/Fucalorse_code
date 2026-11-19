#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090;
const vector<pair<int,int>>h={{-1,0},{0,1},{1,0},{0,-1}};

int n,m,a,b;
char s[MAX][MAX],ans[MAX][MAX];

bool dis(const int &i,const int &j) { return i>=1&&i<=n&&j>=1&&j<=m; }

void solve()
{
    cin>>n>>m>>a>>b;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>s[i][j];
    LL total=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='#')
            {
                ans[i][j]='#';
                continue;
            }
            int cnt=0;
            for(auto &[dx,dy]:h)
            {
                int ni=i+dx,nj=j+dy;
                if(dis(ni,nj)&&s[ni][nj]!='#') ++cnt;
            }
            if(b-cnt>a+cnt) ans[i][j]='B';
            else ans[i][j]='A';
            total+=max(b-cnt,a+cnt);
        }
    cout<<total<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<ans[i][j];
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