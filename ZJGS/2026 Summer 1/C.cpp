#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,INF=2e9,MOD=998244353,G=3,LEN=1e6;

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

void ntt(vector<LL>& a,bool inverse)
{
    int n=a.size();

    for(int i=1,j=0;i<n;i++)
    {
        int bit=n>>1;

        while(j&bit)
        {
            j^=bit;
            bit>>=1;
        }

        j^=bit;
        if(i<j) swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1)
    {
        LL wlen=cal(G,(MOD-1)/len);
        if(inverse) wlen=cal(wlen,MOD-2);

        for(int i=0;i<n;i+=len)
        {
            LL w=1;

            for(int j=0;j<len/2;j++)
            {
                LL u=a[i+j],v=a[i+j+len/2]*w%MOD;

                a[i+j]=(u+v)%MOD;
                a[i+j+len/2]=(u-v+MOD)%MOD;

                w=w*wlen%MOD;
            }
        }
    }

    if(inverse)
    {
        LL inv=cal(n,MOD-2);
        for(auto &cur:a)
            cur=cur*inv%MOD;
    }
}

vector<LL> mutiply(const vector<LL>& a,const vector<LL>& b)
{
    vector<LL>fa(a.begin(),a.end()),fb(b.begin(),b.end());

    int n=1,len=a.size()+b.size()-1;
    while(n<len) n<<=1;

    fa.resize(n),fb.resize(n);

    ntt(fa,false);
    ntt(fb,false);

    for(int i=0;i<n;i++)
        fa[i]=fa[i]*fb[i]%MOD;

    ntt(fa,true);
    fa.resize(len);

    return fa;
}

int n;
LL ans[MAX],f[MAX],inv[MAX],pow_26[MAX];

void create()
{
    f[0]=1;
    for(int i=1;i<=LEN;i++)
        f[i]=f[i-1]*i%MOD;

    inv[LEN]=cal(f[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;

    pow_26[0]=1;
    for(int i=1;i<=LEN;i++)
        pow_26[i]=pow_26[i-1]*26LL%MOD;
}

LL C(int n,int m) { return f[n]*inv[n-m]%MOD*inv[m]%MOD; }

void solve()
{
    cin>>n;

    int m=n/3;
    vector<LL>a(m+1),b(m+1);
    for(int i=0;i<=m;i++)
    {
        a[m-i]=f[i]*C(n-2*i,i)%MOD*pow_26[n-3*i]%MOD;

        if(i&1) b[i]=(-inv[i]+MOD)%MOD;
        else b[i]=inv[i];
    }

    vector<LL>c=mutiply(a,b);
    for(int i=0;i<=m;i++)
        ans[i]=c[m-i]*inv[i]%MOD;

    for(int i=0;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    solve();

    return 0;
}