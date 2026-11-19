#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e6,MOD=998244353,INF=2e9;

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

int n;
LL f[MAX],inv[MAX];
int a[MAX];

LL C(int n,int m) { return f[n]*inv[m]%MOD*inv[n-m]%MOD; }
LL A(int n,int m)
{
    if(n<m) return 0;
    return f[n]*inv[n-m]%MOD;
}

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=qpow(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

void solve()
{
    cin>>n;

    bool ok1=true,ok2=false;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==n) ok1=false;
        if(a[i]==n-1) ok2=true;
    }

    if(!ok1||!ok2)
    {
        cout<<0<<endl;
        return;
    }

    int m=n-1;
    int l=1,r=n;
    for(l=1;l<=m;l++)
        if(a[l]==n-1) break;
    for(r=m;r>=1;r--)
        if(a[r]==n-1) break;

    for(int i=l;i<=r;i++)
        if(a[i]!=a[l])
        {
            cout<<0<<endl;
            return;
        }

    for(int i=2;i<=l;i++)
        if(a[i]<a[i-1])
        {
            cout<<0<<endl;
            return;
        }
    
    for(int i=m-1;i>=r;i--)
        if(a[i]<a[i+1])
        {
            cout<<0<<endl;
            return;
        }

    for(int i=1;i<=l;i++)
        if(i>a[i])
        {
            cout<<0<<endl;
            return;
        }
    
    for(int i=m;i>=r;i--)
        if(n-i>a[i])
        {
            cout<<0<<endl;
            return;
        }

    set<int>st;
    for(int i=1;i<l;i++)
        st.insert(a[i]);
    for(int i=m;i>r;i--)
        if(st.count(a[i]))
        {
            cout<<0<<endl;
            return;
        }

    vector<int>cnt(n+1,0),sum(n+1,0);
    for(int i=1;i<=m;i++)
        ++cnt[a[i]];
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+cnt[i];

    LL con1=1;
    for(int i=1;i<l;i++)
        if(i==1||a[i]!=a[i-1])
        {
            int rest=a[i]-sum[a[i]-1]-1;
            if(rest<cnt[a[i]]-1)
            {
                cout<<0<<endl;
                return;
            }
            LL now=A(rest,cnt[a[i]]-1);
            con1=con1*now%MOD;
        }

    LL con2=1;
    for(int i=m;i>r;i--)
        if(i==m||a[i]!=a[i+1])
        {
            int rest=a[i]-sum[a[i]-1]-1;
            if(rest<cnt[a[i]]-1)
            {
                cout<<0<<endl;
                return;
            }
            LL now=A(rest,cnt[a[i]]-1);
            con2=con2*now%MOD;
        }

    // cout<<con1<<' '<<con2<<endl;
    LL ans=2*con1*con2%MOD*A(cnt[n-1]-1,cnt[n-1]-1)%MOD;
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