#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int t,n,q;
int cnt[MAX];
LL f[MAX],g[MAX];
char s[MAX];

void solve()
{
    cin>>n>>q>>s;
    // cout<<endl;
    for(int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+(s[i-1]=='+')*i;
        g[i]=g[i-1]+(s[i-1]=='-')*i;
        cnt[i]=cnt[i-1]+(s[i-1]=='+');
        // cout<<f[i]<<" "<<g[i]<<endl;
    }
    LL ans=0;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        // cout<<l<<' '<<r<<endl;
        int x=cnt[r]-cnt[l-1];
        // cout<<cnt+((f[r]-f[l+cnt-1])-(g[l+cnt-1]-g[l-1]))*2<<endl;
        ans^=x+((f[r]-f[l+x-1])-(g[l+x-1]-g[l-1]))*2;
    }
    // cout<<endl;
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}