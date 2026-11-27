#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=1e9;
const LL LINF=9e18;

int n,x;
int a[MAX];

void solve()
{
    cin>>n>>x;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    auto check=[&](int mid)->bool
    {
        int other=0;
        for(int i=1,l=1,r=1,pre=-INF;i<=n;i++)
        {
            while(l<=n&&a[i]-a[l]>mid) ++l;
            while(r<=n&&a[r]-a[i]<=mid) ++r;

            if(r-l<=1)
            {
                if(abs(a[i]-pre)>mid)
                {
                    pre=a[i]+mid;
                    ++other;
                }
            }

            if(other>x) return false;
        }
        return other<=x;
    };

    int l=1,r=INF;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    cout<<l<<endl;
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