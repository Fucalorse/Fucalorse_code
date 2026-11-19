#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL k;
LL a[MAX],b[MAX],c[MAX];
bool have_inv[MAX];

bool check(const LL &mid)
{
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        LL sum=a[i]+b[i]+c[i];
        if(sum>=mid) continue;
        if(a[i]==b[i]&&b[i]==c[i]) return false;

        if(have_inv[i]) total+=mid-sum;
        else
        {
            LL cost=min(c[i]-b[i],b[i]-a[i])+1;
            total+=cost;
            sum-=cost;
            total+=mid-sum;
        }

        if(total>k) return false;
    }

    return total<=k;
}

void solve()
{
    cin>>n>>k;

    LL l=LINF,r=-LINF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>b[i]||a[i]>c[i]||b[i]>c[i]) have_inv[i]=true;
        else have_inv[i]=false;

        LL sum=a[i]+b[i]+c[i];
        l=min(l,sum-k);
        r=max(r,sum+k);
    }

    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    cout<<r<<endl;
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