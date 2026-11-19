#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

struct tree
{
    LL x,h;
}op[MAX];

int n;
int dp[MAX][3];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].h;
    
    auto check=[&](LL l1,LL r1,LL l2,LL r2)
    {
        if(r1<l2||l1>r2) return true;
        else return false;
    };

    dp[1][0]=dp[1][2]=1,dp[1][1]=0;

    for(int i=1;i<=n;i++)
    {
        vector<pair<LL,LL>>pre,now;

        pre.push_back({op[i-1].x-op[i-1].h,op[i-1].x});
        pre.push_back({op[i-1].x,op[i-1].x});
        pre.push_back({op[i-1].x,op[i-1].x+op[i-1].h});

        now.push_back({op[i].x-op[i].h,op[i].x});
        now.push_back({op[i].x,op[i].x});
        now.push_back({op[i].x,op[i].x+op[i].h});

        for(size_t j=0;j<pre.size();j++)
            for(size_t k=0;k<now.size();k++)
                if(check(pre[j].first,pre[j].second,now[k].first,now[k].second))
                {
                    if(k==1) dp[i][k]=max(dp[i][k],dp[i-1][j]);
                    else dp[i][k]=max(dp[i][k],dp[i-1][j]+1);
                }
    }

    // for(int i=1;i<=n;i++)
    //     cout<<dp[i][0]<<' '<<dp[i][1]<<' '<<dp[i][2]<<endl;

    cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}