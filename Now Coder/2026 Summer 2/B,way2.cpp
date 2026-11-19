#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=31,MOD=998244353,INF=2e9;

int n;
int a[MAX],f[LEN+3];

void update(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return;
            }

            x^=f[i];
        }
}

int cal()
{
    int ans=0;
    for(int i=LEN;i>=0;i--)
        ans=max(ans,ans^f[i]);
    return ans;
}

void clear()
{
    for(int i=0;i<=LEN;i++)
        f[i]=0;
}

void solve()
{
    cin>>n;clear();

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum^=a[i];
    }

    for(int i=1;i<=n;i++)
    {
        int now=a[i]-(a[i]&sum);
        update(now);
    }

    int ans=sum+2*cal();
    cout<<ans<<endl;
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