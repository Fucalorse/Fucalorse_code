#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=60,MOD=998244353,INF=2e9;

struct qwq
{
    LL C,P,Q,R;
    qwq(int c=0,int p=0,int q=0,int r=0):C(c),P(p),Q(q),R(r){}
};

LL n,d;

void solve()
{
    cin>>n>>d;

    vector<vector<qwq>>dp(2,vector<qwq>(2,qwq{}));
    dp[0][0]=qwq(1,0,0,0);

    for(int k=0;k<=LEN;k++)
    {
        vector<vector<qwq>>ndp(2,vector<qwq>(2,qwq{}));
        int nk=(n>>k)&1,dk=(d>>k)&1;

        for(int c1=0;c1<=1;c1++)
            for(int c2=0;c2<=1;c2++)
                for(int x=0;x<=1;x++)
                {
                    int sum=x+c1+dk;
                    int y=sum&1,nc1=sum>>1,nc2=(nk-x-c2<0);

                    auto &pre=dp[c1][c2];
                    auto &now=ndp[nc1][nc2];

                    now.R=(now.R+pre.R+pre.P*y+pre.Q*x+pre.C*x*y)%MOD;
                    now.P=(now.P+pre.P+pre.C*x)%MOD;
                    now.Q=(now.Q+pre.Q+pre.C*y)%MOD;
                    now.C=(now.C+pre.C)%MOD;
                }

        dp=ndp;
    }

    cout<<dp[0][0].R<<endl;
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