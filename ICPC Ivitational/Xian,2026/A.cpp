#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL a[MAX],f[MAX],d[MAX];

void solve()
{
    cin>>n;

    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
        sum+=a[i];
    }

    if(sum%n!=0)
    {
        cout<<-1<<endl;
        return;
    }

    LL target=sum/n;
    for(int i=1;i<=n;i++)
    {
        d[i]=1LL*i*target-f[i];
        if(d[i]<0)
        {
            cout<<-1<<endl;
            return;
        }
    }

    LL ans=0;
    vector<vector<LL>>wait(2,vector<LL>{});
    wait[0].push_back(0);
    wait[1].push_back(0);

    for(int i=1;i<n;i++)
        wait[i&1].push_back(d[i]);

    for(auto &op:wait)
    {
        int len=op.size();
        for(int i=1;i<len;i++)
            if(op[i]>op[i-1]) ans+=op[i]-op[i-1];
    }

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