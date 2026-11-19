#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=59,G=3,MOD=1e9+7,INF=2e9;
const LL LINF=1e18;

LL qpow(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;
        p>>=1;
    }
    return ans;
}

template <class T>
auto make_vec(T val) { return val; }

template <class T,class...Args>
auto make_vec(T val,int n,Args...args) { return vector(n,make_vec(val,args...)); }

LL n;

void solve()
{
    cin>>n;

    LL dp[2][2][2][2]={},ndp[2][2][2][2];
    dp[0][0][0][0]=1LL;

    for(int k=LEN;k>=0;k--)
    {
        int pn=(n>>k)&1;
        memset(ndp,0,sizeof(ndp));

        for(int sa=0;sa<=1;sa++)
            for(int sc=0;sc<=1;sc++)
                for(int pa=0;pa<=1;pa++)
                    for(int pc=0;pc<=1;pc++)
                    {
                        LL cnt=dp[pa][pc][sa][sc];
                        if(!cnt) continue;

                        for(int u=0;u<=1;u++)
                            for(int v=0;v<=1;v++)
                            {
                                bool fa=sa|(u<=pn),fc=sc|(v<=pn),same=(pa^pc)==(u&v);
                                if(!fa||!fc||!same) continue;

                                int nsa=sa|(u<pn),nsc=sc|(v<pn);
                                ndp[u][v][nsa][nsc]=(ndp[u][v][nsa][nsc]+cnt)%MOD;
                            }
                    }

        memcpy(dp,ndp,sizeof(dp));
    }

    LL ans=0;
    for(auto p:{0,1})
        for(auto sa:{0,1})
            for(auto sc:{0,1})
                ans=(ans+dp[p][p][sa][sc])%MOD;

    ans=(ans-1+MOD)%MOD;
    cout<<ans*qpow(2,MOD-2)%MOD<<endl;
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