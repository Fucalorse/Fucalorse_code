#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=6090,inf=2e9;

struct qwq
{
    int st,len;
};

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<vector<bool>>dp(n+1,vector<bool>(n+1,false));
    for(int i=1;i<=n;i++)
    {
        unordered_map<int,int>f;
        int cnt=0,maxn=-inf,minn=inf;

        for(int j=i;j<=n;j++)
        {
            if(++f[a[j]]==2) break;

            maxn=max(maxn,a[j]);
            minn=min(minn,a[j]);
            ++cnt;

            if(maxn-minn+1==cnt) dp[minn][maxn]=true;
        }
    }

    int ans=0;
    for(int len=1;len<=n/2;++len)
        for(int st=1;st<=n;++st)
        {
            if(st+2*len-1<=n)
            {
                if(dp[st][st+len-1]&&dp[st+len][st+2*len-1]) ans=len;
            }

            if(st-2*len+1>=1)
            {
                if(dp[st-len+1][st]&&dp[st-2*len+1][st-len]) ans=len;
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