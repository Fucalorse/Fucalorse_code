#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e7,MOD=998244353,INF=2e9;

int n;
string a,b;

void solve()
{
    cin>>n>>a>>b;a=' '+a,b=' '+b;

    int a0=0,a1=0,b0=0,b1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='1')
        {
            if(i&1) ++a1;
            else ++a0;
        }

        if(b[i]=='1')
        {
            if(i&1) ++b1;
            else ++b0;
        }
    }

    if(a0!=b0||a1!=b1)
    {
        cout<<-1<<endl;
        return;
    }

    auto cal=[&](int k)
    {
        LL ans=0;

        vector<int>posa,posb;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='1'&&((i&1)==k)) posa.push_back(i);
            
            if(b[i]=='1'&&((i&1)==k)) posb.push_back(i);
        }

        for(size_t i=0;i<posa.size();i++)
            ans+=abs(posa[i]-posb[i]);

        return ans;
    };

    LL ans=cal(1)+cal(0);
    cout<<ans/2<<endl;
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