#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
LL a[MAX],op[MAX];

void solve()
{
    cin>>n;

    auto cal=[&](LL num)
    {
        LL ans=0;
        while(num)
        {
            LL x=num%10;
            ans+=x*x;
            num/=10;
        }
        return ans;
    };

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]=a[i];

        for(int round=1;round<=1000;++round)
            op[i]=cal(op[i]);
    }

    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(op[i]==op[j]) ++ans;

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