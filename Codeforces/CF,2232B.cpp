#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long 
const int MAX=1e6+90;

int T,n;
LL a[MAX],sum[MAX],ans[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }

    ans[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]>=ans[i-1]) ans[i]=ans[i-1];
        else
        {
            LL l=0,r=ans[i-1];

            auto check=[&](const LL &mid)
            {
                LL cost=mid*i;

                if(sum[i]>=cost) return true;
                else return false;
            };

            while(l<=r)
            {
                LL mid=(l+r)>>1;

                if(check(mid)) l=mid+1;
                else r=mid-1;
            }

            ans[i]=r;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}