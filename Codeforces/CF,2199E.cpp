#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,q;
LL a[MAX],f[MAX];

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1];
        if(a[i]!=a[i-1]) f[i]+=llabs(a[i]-a[i-1])-1;
        else f[i]++;
    }

    // for(int i=2;i<=n;i++)
    //     cout<<f[i]<<' ';
    // cout<<endl;

    for(int i=1;i<=q;i++)
    {
        LL x;
        cin>>x;
        
        if(x>f[n]+n) cout<<-1<<' ';
        else if(x==f[n]+n) cout<<a[n]<<' ';
        else
        {
            int l=1,r=n;
            while(l<=r)
            {
                int mid=(l+r)>>1;
                LL now=f[mid]+mid;
                // cout<<mid<<' '<<now<<endl;
                if(now>x) r=mid-1;
                else l=mid+1;
            }
            int pos=r;
            LL rest=x-(f[pos]+pos);

            if(!rest)
            {
                cout<<a[pos]<<' ';
                continue;
            }
            if(a[pos]==a[pos+1]) cout<<0<<' ';
            else
            {
                int dx=a[pos]<a[pos+1]?1:-1;
                cout<<a[pos]+dx*rest<<' ';
            }
        }
    }
    cout<<endl;
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