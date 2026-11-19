#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
LL a[MAX],sum[MAX],maxn[MAX],suf[MAX];

LL C(LL n,LL m)
{
    LL ans=1;
    for(LL i=1;i<=m;i++)
        ans=ans*(n-i+1)/i;
    return ans;
}

void solve()
{
    cin>>n;

    auto get_max=[&](int x)
    {
        int ans=0;
        while(x)
        {
            ans=max(ans,x%10);
            x/=10;
        }
        return ans;
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        maxn[i]=get_max(a[i]);
    }

    LL ans=0;
    for(int d=1;d<=9;d++)
    {
        vector<LL>op,cnt(d,0);
        op.push_back(0LL);
        for(int i=1;i<=n;i++)
        {
            LL now=sum[i]%d;
            if(maxn[i]<d)
            {
                ans+=cnt[now];
                op.push_back(now);
            }
            else if(maxn[i]==d)
            {
                for(auto &cur:op)
                    cnt[cur]++;
                ans+=cnt[now];
                op.clear();
                op.push_back(now);
            }
            else
            {
                op.clear();
                for(int j=0;j<d;j++)
                    cnt[j]=0;
                op.push_back(now);
            }
        }
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}