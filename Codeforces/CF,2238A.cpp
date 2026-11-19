#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353;
const LL INF=1e18;

int n;
LL c;
LL a[MAX],b[MAX];

LL cal_first()
{
    LL ans=0;

    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i]) return INF;
        ans+=a[i]-b[i];
    }

    return ans;
}

void solve()
{
    cin>>n>>c;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    LL num1=cal_first(),num2=c;
    
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    for(int i=1;i<=n;i++)
    {
        if(a[i]<b[i])
        {
            cout<<-1<<endl;
            return;
        }
        num2+=a[i]-b[i];
    }

    cout<<min(num1,num2)<<endl;
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