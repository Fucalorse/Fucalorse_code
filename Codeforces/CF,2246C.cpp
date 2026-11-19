#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,INF=2e9,MOD=1e9+7;

LL qpow(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%MOD;
        a=a*a%MOD;

        p>>=1;
    }

    return ans;
}

int T,n;
LL a[MAX];

void solve()
{
    cin>>n;

    int total=0;
    map<int,int>f;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==-1) ++total;
        else ++f[a[i]];
    }

    LL con1=1;
    for(auto &[val,cnt]:f)
        con1=con1*qpow(2LL,cnt-1)%MOD;

    int c=0;
    for(auto l=f.begin();l!=f.end();++l)
    {
        auto r=l;++r;
        if(r==f.end()) break;
        if(l->first+1!=r->first) continue;

        ++c;
    }

    LL con2=con1*c%MOD,even,odd;
    if(!total)
    {
        even=1;
        odd=0;
    }
    else even=odd=qpow(2LL,total-1);

    LL ans=even*con1%MOD;
    ans=(ans+odd*con2%MOD)%MOD;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}