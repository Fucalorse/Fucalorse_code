#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=43046722,LEN=16,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int n;
int pw[MAX],first[MAX];
int dp[MAX],a[MAX];

void create()
{
    pw[0]=1;
    for(int i=1;i<=LEN;i++)
        pw[i]=pw[i-1]*3;
}

void solve()
{
    cin>>n;

    auto cal=[&](int num)
    {
        int ans=0;
        vector<int>bit;
        while(num)
        {
            bit.push_back(num&1);
            num>>=1;
        }

        for(auto it=bit.rbegin();it!=bit.rend();++it)
            ans=ans*3+*it;

        return ans;
    };

    for(int i=0;i<(1<<n);i++)
    {
        cin>>a[i];
        int mask=cal(i);
        dp[mask]=a[i];
        first[mask]=-1;
    }

    int S=pw[n],ans=0;
    first[0]=-1;
    for(int mask=1;mask<S;mask++)
    {
        if(mask%3==2) first[mask]=0;
        else
        {
            int pos=first[mask/3];
            first[mask]=pos==-1?-1:pos+1;
        }
    }

    for(int mask=0;mask<S;mask++)
    {
        if(first[mask]==-1)
        {
            ans^=dp[mask];
            continue;
        }

        int target=2*pw[first[mask]];
        int mask_left=mask-target,mask_right=mask-target+pw[first[mask]];
        dp[mask]=dp[mask_left]+dp[mask_right];
        ans^=dp[mask];
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}