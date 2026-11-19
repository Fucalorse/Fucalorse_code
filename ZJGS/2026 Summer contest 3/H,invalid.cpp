#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=5090,LEN=32,MOD=998244353,INF=2e9;

string s;

bool check(char c)
{
	return c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
}

void solve()
{
	cin>>s;
	int n=s.size();
	s='A'+s;
	
	vector<vector<LL>>dp(n+1,vector<LL>(3,-INF));
    vector<LL>best(3,-INF),bestN(3,-INF);
	dp[0][2]=best[2]=0;

	for(int i=1;i<=n;i++)
	{
		if(check(s[i])||s[i]=='Y')
		{
			if(s[i]=='Y')
			{
                if(best[0]!=-INF) dp[i][2]=max(dp[i][2],best[0]+1);
                if(best[2]!=-INF) dp[i][1]=max(dp[i][1],best[2]+1);
                if(best[1]!=-INF) dp[i][0]=max(dp[i][0],best[1]+1);
			}
			else
			{
                if(best[1]!=-INF) dp[i][0]=max(dp[i][0],best[1]+1);
			}

            for(int j=0;j<3;j++)
                best[j]=max(best[j],dp[i][j]);
		}
		else
		{
            if(best[0]!=-INF) dp[i][2]=max(dp[i][2],best[0]+1);
            if(best[2]!=-INF) dp[i][1]=max(dp[i][1],best[2]+1);
           
			if(s[i]=='G')
			{
                if(bestN[1]!=-INF) dp[i][1]=max(dp[i][1],bestN[1]+1);
                if(bestN[2]!=-INF) dp[i][2]=max(dp[i][2],bestN[2]+1);
			}

            for(int j=0;j<3;j++)
                best[j]=max(best[j],dp[i][j]);

            if(s[i]=='N')
            {
                for(int j=0;j<3;j++)
                    bestN[j]=max(bestN[j],dp[i][j]);
            }
		}
	}
	
	LL ans=-INF;
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][2]);
		
	if(ans<3) cout<<0<<endl;
	else cout<<ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int T=1;
//	cin>>T;
	while(T--) solve();
	
	return 0;
}