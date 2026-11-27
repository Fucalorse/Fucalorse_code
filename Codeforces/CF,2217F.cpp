#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=19,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int x1,x2;

void solve()
{
    cin>>x1>>x2;

    if(x1-1>=x2)
    {
        cout<<1<<' '<<1<<endl;
        return;
    }

    LL minn=LINF;
    int best=-1;
    for(int s=0;s<x1;s++)
    {
        int up=(x2-1-s)>>1;
        LL dp[2][2][2]={},ndp[2][2][2]={};
        dp[0][0][1]=1;

        for(int k=LEN;k>=0;k--)
        {
            memset(ndp,0,sizeof(ndp));
            int ns=(s>>k)&1,max_bit=(up>>k)&1;
            vector<pair<int,int>>wait;
            if(ns==1) wait={{0,1},{1,0}};
            else wait={{0,0},{1,1}};

            for(auto pa:{0,1})
                for(auto pb:{0,1})
                {
                    for(const auto &[na,nb]:wait)
                    {
                        int sum_and=na&nb;
                        if(sum_and>max_bit) ndp[na][nb][0]+=dp[pa][pb][0];
                        else if(sum_and==max_bit)
                        {
                            ndp[na][nb][1]+=dp[pa][pb][1];
                            ndp[na][nb][0]+=dp[pa][pb][0];
                        }
                        else ndp[na][nb][0]+=dp[pa][pb][0]+dp[pa][pb][1];
                    }
                }

            memcpy(dp,ndp,sizeof(ndp));
        }

        LL now=0;
        for(int pa:{0,1})
            for(int pb:{0,1})
                for(int col:{0,1})
                    now+=dp[pa][pb][col];

        if(now<minn)
        {
            minn=now;
            best=s;
        }
    }

    cout<<1<<' '<<x1-best<<endl;
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