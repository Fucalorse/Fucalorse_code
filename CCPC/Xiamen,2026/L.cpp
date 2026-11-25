#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL r,s;
LL a[MAX],b[MAX];

void solve()
{
    cin>>n>>r>>s;
    s+=3*r;

    vector<LL>zero;
    vector<pair<LL,LL>>other;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        if(b[i]==0) zero.push_back(a[i]);
        else other.push_back({a[i],b[i]});
    }

    LL ans=0;
    sort(zero.begin(),zero.end(),greater<LL>());
    int pos_zero=0,pos_other=0;
    while(1)
    {
        LL cnt=(s-1)/3;
        while(cnt--&&pos_zero<(int)zero.size())
        {
            ans+=zero[pos_zero];
            ++pos_zero;
        }

        if(pos_other<(int)other.size())
        {
            auto [a,b]=other[pos_other++];
            ans+=a;
            s=b;
        }
        else break;
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