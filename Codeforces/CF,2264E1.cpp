#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=3000,G=3,MOD=998244353,INF=2e9;

int minp[MAX],rad[MAX];
vector<int>op;

void oula(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!minp[i])
        {
            minp[i]=i;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if(1LL*i*j>n) break;
            minp[i*j]=j;
            if(i%j==0) break;
        }
    }

    auto split=[&](int num)
    {
        set<int>st;
        while(num!=1)
        {
            st.insert(minp[num]);
            num/=minp[num];
        }
        return st;
    };

    for(int i=1;i<=n;i++)
    {
        rad[i]=1;
        set<int>st=split(i);
        for(auto &cur:st)
            rad[i]=rad[i]*cur;
    }
}

int n;
int a[MAX],dp[3090][3090];
LL pw2[MAX];

void create()
{
    oula(LEN);

    pw2[0]=1;
    for(int i=1;i<=LEN;i++)
        pw2[i]=pw2[i-1]*2%MOD;

    for(int j=1;j<=LEN;j++)
    {
        dp[j][j]=j;

        for(int i=1;i<j;i++)
        {
            if(i%rad[j]==0) dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            else dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
}

void solve()
{
    cin>>n;

    vector<int>cnt(n+1,0LL),sum(n+1,0LL);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+cnt[i];

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i])
        {
            LL total=(pw2[cnt[i]]-1+MOD)%MOD;
            ans=(ans+total*i%MOD)%MOD;

            for(int j=i+1;j<=n;j++)
            {
                if(!cnt[j]) continue;

                LL left=(pw2[cnt[i]]-1+MOD)%MOD;
                LL middle=pw2[sum[j-1]-sum[i]];
                LL right=(pw2[cnt[j]]-1+MOD)%MOD;
                LL total=left*middle%MOD*right%MOD;
                ans=(ans+total*dp[i][j]%MOD)%MOD;
            }
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}