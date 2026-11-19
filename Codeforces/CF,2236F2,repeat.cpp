#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=5e5,G=3,MOD=1e9+7,INF=2e9;

int minp[MAX];
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
}

int n,x;
int a[MAX];

void solve()
{
    cin>>n>>x;

    map<int,int>cntx,cnta;
    map<int,vector<int>>each;

    auto split_first=[&](int num)
    {
        while(num!=1)
        {
            ++cntx[minp[num]];
            num/=minp[num];
        }
    };
    split_first(x);

    auto split=[&](int num)
    {
        map<int,int>cur;
        while(num!=1)
        {
            ++cur[minp[num]];
            num/=minp[num];
        }

        for(auto &[val,cnt]:cur)
        {
            cnta[val]+=cnt;
            if(cntx.count(val)) each[val].push_back(cnt);
        }
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        split(a[i]);
    }

    LL ans=1;
    for(auto &[prime,cx]:cntx)
    {
        if(!each.count(prime))
        {
            cout<<0<<endl;
            return;
        }

        int ed=0;
        auto &op=each[prime];
        for(auto &cur:op)
            ed=max(ed,cur);

        LL res=0;
        int need=cx+ed;
        vector<LL>pre(need+1,0);

        for(int maxn=1;maxn<=ed;maxn++)
        {
            vector<LL>dp(need+1,0);
            dp[0]=1;

            for(auto &cnt:op)
            {
                LL sum=0;
                int ceil=min(cnt,maxn);
                vector<LL>ndp(need+1,0);

                for(int i=0;i<=need;i++)
                {
                    if(i-ceil-1>=0)
                    {
                        LL now=dp[i-ceil-1];
                        sum=(sum-now)%MOD;
                        sum=(sum+MOD)%MOD;
                    }
                    sum=(sum+dp[i])%MOD;
                    ndp[i]=(ndp[i]+sum)%MOD;
                }

                dp=ndp;
            }

            int total=cx+maxn;
            res=(res+dp[total]-pre[total])%MOD;
            res=(res+MOD)%MOD;
            pre=dp;
        }

        if(!res)
        {
            cout<<0<<endl;
            return;
        }

        ans=ans*res%MOD;
    }

    for(auto &[val,cnt]:cnta)
        if(!cntx.count(val)) ans=ans*(cnt+1)%MOD;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}