#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=5e5,mod=1e9+7;

int T,n,x;
int a[MAX],minp[MAX];
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
            if((LL)i*j>n) break;

            minp[i*j]=j;
            if(i%j==0) break;
        }
    }
}

void solve()
{
    cin>>n>>x;

    map<int,int>cntx,cnta;
    map<int,vector<int>>rest;

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
        map<int,int>now;

        while(num!=1)
        {
            ++now[minp[num]];
            num/=minp[num];
        }

        for(auto &[val,cnt]:now)
        {
            if(cntx.count(val)) rest[val].push_back(cnt);
            cnta[val]+=cnt;
        }
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        split(a[i]);
    }

    LL ans=1;
    for(auto &[val,needx]:cntx)
    {
        auto &wait=rest[val];

        if(wait.empty())
        {
            cout<<0<<endl;
            return;
        }

        int ed=0;
        for(auto &cur:wait)
            ed=max(ed,cur);

        LL res=0;
        int need=ed+cntx[val];
        vector<LL>pre(need+1,0);
        pre[0]=1;

        for(int maxn=1;maxn<=ed;maxn++)
        {
            vector<LL>dp(need+1,0);
            dp[0]=1;

            for(auto &cnt:wait)
            {
                vector<LL>ndp(need+1,0);
                int ceil=min(cnt,maxn);
                LL sum=0;

                for(int k=0;k<=need;k++)
                {
                    sum=(sum+dp[k])%mod;

                    if(k-ceil-1>=0)
                    {
                        sum=(sum-dp[k-ceil-1])%mod;
                        sum=(sum+mod)%mod;
                    }

                    ndp[k]=sum;
                }

                dp=ndp;
            }
            
            int now_need=maxn+cntx[val];
            res+=dp[now_need]-pre[now_need];
            res=(res%mod+mod)%mod;

            pre=dp;
        }

        if(!res)
        {
            cout<<0<<endl;
            return;
        }

        ans=(ans*res)%mod;
    }

    for(auto &[val,cnt]:cnta)
    {
        if(cntx.count(val)) continue;

        ans=(ans*(cnt+1))%mod;
    }
    
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    oula(LEN);
    cin>>T;
    while(T--) solve();

    return 0;
}