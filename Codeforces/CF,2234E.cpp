#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=5e5+90,mod=1e9+7,LEN=5e5;

int T,n;
LL a[MAX],ans,inv[MAX],f[MAX];

LL cal(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }

    return ans;
}

void create()
{
    f[0]=f[1]=1;
    for(int i=2;i<=LEN;i++)
        f[i]=f[i-1]*i%mod;
    
    inv[LEN]=cal(f[LEN],mod-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%mod;
}

LL C(int n,int m) { return f[n]*inv[n-m]%mod*inv[m]%mod; }

bool check(int l,int r,int i)
{
    LL now=1LL*(i-l+1)*(r-i+1);

    return now==a[i];
}

bool dfs(int l,int r)
{
    if(l>r) return true;

    int root=-1;
    for(int d=0;l+d<=r-d;d++)
    {
        if(check(l,r,l+d))
        {
            root=l+d;
            ans=ans*C(r-l,d);
            ans%=mod;
            break;
        }
        
        if(check(l,r,r-d))
        {
            root=r-d;
            ans=ans*C(r-l,d);
            ans%=mod;
            break;
        }
    }
    // printf("%d ",root);

    if(root==-1) return false;

    if(dfs(l,root-1)&&dfs(root+1,r)) return true;

    return false;
}

void solve()
{
    cin>>n;

    LL sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }

    if(sum!=1LL*n*(n+1)/2)
    {
        cout<<0<<endl;
        return;
    }

    ans=1;
    if(dfs(1,n)) cout<<ans<<endl;
    else cout<<0<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    cin>>T;
    while(T--) solve();

    return 0;
}