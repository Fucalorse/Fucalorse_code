#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
LL c[MAX];

void solve()
{
    cin>>n;

    int c1=0;
    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==1) ++c1;
        sum+=c[i];
    }

    if(c1==n||sum<=2) cout<<0<<endl;
    else if(c1==n-1)
    {
        for(int i=1;i<=n;i++)
            if(c[i]>1)
            {
                LL pair=c[i]/2;
                cout<<c[i]+min(pair,(LL)c1)<<endl;
                break;
            }
    }
    else
    {
        LL pair=0,ans=0;
        for(int i=1;i<=n;i++)
            if(c[i]>1)
            {
                ans+=c[i];
                pair+=max(0LL,c[i]/2-1);
            }

        ans+=min(pair,(LL)c1);
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}