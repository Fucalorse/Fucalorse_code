#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=998244353,INF=2e9;

LL qpow(LL a,LL p)
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
        LL wlen=qpow(G,(MOD-1)/len);
        if(inverse) wlen=qpow(wlen,MOD-2);

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
        LL inv=qpow(n,MOD-2);
        for(auto &cur:a)
            cur=cur*inv%MOD;
    }
}

vector<LL> multiply(const vector<LL>& a,const vector<LL>& b)
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
LL x[MAX],y[MAX],fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

LL C(int n,int m) { return fac[n]*inv[n-m]%MOD*inv[m]%MOD; }

void solve()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        x[i]=(x[i]%MOD+MOD)%MOD;
        y[i]=(y[i]%MOD+MOD)%MOD;
    }
    
    vector<LL>A(n),B(n);
    for(int i=0;i<n;i++)
        A[i]=x[i],B[i]=y[n-1-i];

    vector<LL>f=multiply(A,B),T(n),S(n);
    for(int d=1;d<=n-1;d++)
        T[d]=(f[n-1-d]-f[n+d-1]+MOD)%MOD;

    for(int d=1;d<=n-1;d++)
        S[d]=(T[d]-T[n-d]+MOD)%MOD;

    vector<LL>a(n),U(n-1),V(n-1);
    for(int i=0;i<n;i++)
        a[i]=S[n-1-i];

    for(int i=0;i<n-1;i++)
    {
        U[i]=a[n-2-i]*fac[n-2-i]%MOD;
        V[i]=inv[i];
    }

    vector<LL>op=multiply(U,V);
    for(int k=3;k<=n;k++)
    {
        int r=k-2;
        LL now=op[n-2-r]*inv[r]%MOD;
        cout<<now<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    create();
    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}