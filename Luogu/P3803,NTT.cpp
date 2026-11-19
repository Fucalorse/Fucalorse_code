#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,MOD=998244353,G=3;

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

void ntt(vector<LL>& a,bool invert)
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
        if(invert) wlen=cal(wlen,MOD-2);

        for(int i=0;i<n;i+=len)
        {
            LL w=1;

            for(int j=0;j<len/2;j++)
            {
                // assert(i+j<n);
                // assert(i+j+len/2<n);
                LL u=a[i+j],v=a[i+j+len/2]*w%MOD;

                a[i+j]=(u+v)%MOD;
                a[i+j+len/2]=(u-v+MOD)%MOD;

                w=w*wlen%MOD;
            }
        }
    }

    if(invert)
    {
        LL inv=cal(n,MOD-2);
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

int T,n,m;
int f[MAX],g[MAX];

void solve()
{
    cin>>n>>m;++n,++m;

    vector<LL>a(n),b(m);

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];

    vector<LL>ans=multiply(a,b);

    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    T=1;
    while(T--) solve();

    return 0;
}