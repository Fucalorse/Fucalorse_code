#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    LL first=-1;

    auto check_first=[&]()
    {
        LL pre=0;
        for(int round=0;round<=LEN;round++)
            for(int i=1;i<=n;i++)
                pre=(a[i]+pre)/2;

        ++pre;
        for(int i=1;i<=n;i++)
        {
            LL now=a[i]+pre;
            if(now<0) return false;
            if(llabs(now)&1) return false;
            pre=now/2;
        }

        first=pre;
        return true;
    };

    if(!check_first())
    {
        cout<<-1<<endl;
        return;
    }

    auto check=[&](LL k)
    {
        LL st=first-k,pre=st;
        if(st<0) return false;

        for(int i=1;i<=n;i++)
        {
            LL now=a[i]+pre-k;
            if(now<0) return false;
            pre=now>>1;
        }

        return true;
    };

    LL l=0,r=sum/n;
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }

    if(r<0) cout<<-1<<endl;
    else cout<<sum-r*n<<endl;
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