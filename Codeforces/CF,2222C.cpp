#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int t,n;
int a[MAX],b[MAX],col[MAX];
int f[MAX],cnt[MAX],dp[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    for(int i=1,mid=b[(n+1)>>1];i<=n;i++)
    {
        if(a[i]==mid) col[i]=0;
        else if(a[i]<mid) col[i]=-1;
        else col[i]=1;
        f[i]=f[i-1]+col[i];
        cnt[i]=cnt[i-1]+(col[i]==0);
        dp[i]=0;
    }
    // for(int i=1;i<=n;i++)
    //     cout<<cnt[i]<<' '<<f[i]<<endl;
    for(int i=1;i<=n;i++)
    {
        int st=i%2==1?0:1;
        for(int j=st;j<=i;j+=2)
        {
            if(j&&!dp[j]) continue;
            if(abs(f[i]-f[j])<cnt[i]-cnt[j]&&cnt[i]-cnt[j])
                dp[i]=max(dp[i],dp[j]+1);
        }
        // cout<<dp[i]<<' ';
    }
    // cout<<endl;
    cout<<dp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}