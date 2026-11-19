#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=305,LEN=300,MOD=1e9+7,INF=2e9;

int n,q;
LL dp[MAX][3][MAX][MAX];
int id[MAX];
string s;

void solve()
{
    cin>>n>>q>>s;s=' '+s;

    int cnt=0;
    id['a']=0,id['b']=1,id['c']=2;

    if(s[1]=='?') dp[1][0][1][0]=dp[1][1][0][1]=dp[1][2][0][0]=1,++cnt;
    else
    {
        int col=id[s[1]];
        dp[1][col][0][0]=1;
    }

    for(int i=2;i<=n;i++)
    {
        if(s[i]=='?') ++cnt;

        if(s[i]!='?')
        {
            int col=id[s[i]];

            for(int k=0;k<=2;k++)
                if(col!=k)
                {
                    for(int u=0;u<=300;u++)
                        for(int v=0;v<=300;v++)
                        {
                            if(dp[i-1][k][u][v]==0) continue;

                            dp[i][col][u][v]=(dp[i][col][u][v]+dp[i-1][k][u][v])%MOD;
                        }
                }
        }
        else
        {
            for(int col=0;col<=2;col++)
            {
                for(int k=0;k<=2;k++)
                    if(col!=k)
                    {
                        if(col==0)
                        {
                            for(int u=0;u<=300;u++)
                                for(int v=0;v<=300;v++)
                                {
                                    if(dp[i-1][k][u][v]==0) continue;

                                    dp[i][col][u+1][v]=(dp[i][col][u+1][v]+dp[i-1][k][u][v])%MOD;
                                }
                        }
                        else if(col==1)
                        {
                            for(int u=0;u<=300;u++)
                                for(int v=0;v<=300;v++)
                                {
                                    if(dp[i-1][k][u][v]==0) continue;

                                    dp[i][col][u][v+1]=(dp[i][col][u][v+1]+dp[i-1][k][u][v])%MOD;
                                }
                        }
                        else
                        {
                            for(int u=0;u<=300;u++)
                                for(int v=0;v<=300;v++)
                                {
                                    if(dp[i-1][k][u][v]==0) continue;

                                    dp[i][col][u][v]=(dp[i][col][u][v]+dp[i-1][k][u][v])%MOD;
                                }
                        }
                    }                
            }
        }
    }

    for(int col=0;col<=2;++col)
        for(int u=0;u<=300;u++)
            for(int v=1;v<=300;v++)
                dp[n][col][u][v]=(dp[n][col][u][v]+dp[n][col][u][v-1])%MOD;

    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;

        LL ans=0;
        for(int col=0;col<=2;++col)
        {
            for(int i=0;i<=x;i++)
            {
                int l=max(cnt-i-z,0),r=min(cnt-i,y);
                if(l>r) continue;

                if(l==0) ans=(ans+dp[n][col][i][r])%MOD;
                else
                {
                    ans=(ans+dp[n][col][i][r]-dp[n][col][i][l-1])%MOD;
                    ans=(ans+MOD)%MOD;
                }
            }
        }

        cout<<ans<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ B.cpp -O2 -o .\out.exe && .\out.exe < in.txt