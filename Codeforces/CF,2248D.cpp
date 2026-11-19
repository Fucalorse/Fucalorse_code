#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=26,MOD=998244353,INF=2e9;

int n,q;
int a[MAX],f[MAX],g[MAX];
string s,t;

void solve()
{
    cin>>n>>q>>s>>t;s=' '+s,t=' '+t;

    for(int i=1;i<=n;i++)
    {
        int u=s[i]-'0',v=t[i]-'0';
        a[i]=u^v;
        
        f[i]=f[i-1];
        g[i]=g[i-1];

        if(a[i])
        {
            if(u==1&&v==0) f[i]++;
            else g[i]++;
        }
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int u=f[r]-f[l-1],v=g[r]-g[l-1];
        int rest=abs(u-v),same=r-l+1-u-v;

        if(rest<=same) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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