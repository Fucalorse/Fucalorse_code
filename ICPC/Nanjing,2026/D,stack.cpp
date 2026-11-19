#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct qwq
{
    LL w;
    int c;
    bool operator<(const qwq &a)const { return w<a.w; }
}op[MAX];

struct node
{
    LL rest,sum,maxn;
    node(LL _rest=0,LL _sum=0,LL _maxn=0):rest(_rest),sum(_sum),maxn(_maxn){}
};

int n,m;

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>op[i].w>>op[i].c;
    
    sort(op+1,op+n+1);
    vector<LL>dp(m+1,0LL);
    vector<vector<node>>fu(m+1,vector<node>{});
    for(int i=1;i<=n;i++)
    {
        const auto &[w,c]=op[i];
        for(int k=m;k>=c;k--)
        {
            auto &pre=fu[k-c];
            while(pre.size()&&pre.back().rest<w-1) pre.pop_back();
            LL sum=pre.size()?pre.back().maxn:0LL;
            if(sum||(sum==0LL&&w==1))
            {
                dp[k]=max(dp[k],sum+w);
                auto &st=fu[k];
                node nxt={sum,sum+w,sum+w};
                while(st.size()&&sum>=st.back().rest) st.pop_back();
                if(st.size()) nxt.maxn=max(nxt.maxn,st.back().maxn);
                st.push_back(nxt);
            }
        }
    }

    cout<<dp[m]<<endl;
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