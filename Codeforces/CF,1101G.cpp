#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=998244353,INF=2e9;

int n;
int a[MAX],sum[MAX],f[LEN+3];

void clear()
{
    for(int i=0;i<=LEN;i++)
        f[i]=0;
}

bool update(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return true;
            }

            x^=f[i];
        }

    return false;
}

void solve()
{
    cin>>n;clear();

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }

    if(!sum[n])
    {
        cout<<-1<<endl;
        return;
    }

    update(sum[n]);

    int ans=1;
    for(int i=1;i<n;i++)
        if(update(sum[i])) ++ans;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}