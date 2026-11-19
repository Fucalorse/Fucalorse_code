#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e5+10,MOD=998244353,INF=2e9,LEN=1e5;

LL cal(LL a,int p)
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

int n,k;
LL f[MAX],inv[MAX];
string s;

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=cal(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return f[n]*inv[m]%MOD*inv[n-m]%MOD; }

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    vector<int>id;
    id.push_back(0);
    for(int i=1;i<=n;i++)
        if(s[i]=='1') id.push_back(i);
    id.push_back(n+1);
    
    if((int)id.size()-2<k)
    {
        cout<<0<<endl;
        return;
    }

    // for(auto &cur:id)
    //     cout<<cur<<' ';
    // cout<<endl;

    LL ans=0;
    for(int i=1;i<(int)id.size()-k;i++)
    {
        int now_l=id[i-1]+1,now_r=id[i+k]-1;
        ans+=C(now_r-now_l+1,k);
        if(i>1)
        {
            int pre_l=id[i-1]+1,pre_r=id[i+k-1]-1;
            ans-=C(pre_r-pre_l+1,k-1);
        }
        ans=(ans%MOD+MOD)%MOD;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}