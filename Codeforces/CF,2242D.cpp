#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5090,INF=1e9;

int T;
int fa[MAX],fb[MAX];
string a,b;

void solve()
{
    cin>>a>>b;a=' '+a,b=' '+b;

    int n=a.size()-1,m=b.size()-1;

    for(int i=1;i<=n;i++)
    {
        int now=a[i]-'0';
        fa[i]=(fa[i-1]+now)%10;
    }

    for(int i=1;i<=m;i++)
    {
        int now=b[i]-'0';
        fb[i]=(fb[i-1]+now)%10;
    }

    if(fa[n]!=fb[m])
    {
        cout<<-1<<endl;
        return;
    }

    vector<vector<int>>dp(n+1,vector<int>(m+1,-INF));
    vector<vector<int>>best(m+1,vector<int>(10,-INF));

    for(int j=0;j<=m;j++)
        best[j][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int now=(fa[i]-fb[j]+10)%10;

            if(best[j-1][now]!=-INF) dp[i][j]=best[j-1][now]+1;
        }

        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=9;k++)
                best[j][k]=max(best[j][k],best[j-1][k]);

            if(dp[i][j]==-INF) continue;
            int now=(fa[i]-fb[j]+10)%10;

            best[j][now]=max(best[j][now],dp[i][j]);
        }
    }

    cout<<dp[n][m]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}