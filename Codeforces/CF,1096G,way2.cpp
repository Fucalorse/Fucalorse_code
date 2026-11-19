#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=998244353,G=3;

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

void ntt(vector<LL>& a,bool insert)
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
        if(insert) wlen=cal(wlen,MOD-2);

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

    if(insert)
    {
        LL inv_n=cal(n,MOD-2);
        for(auto &cur:a)
            cur=cur*inv_n%MOD;
    }
}

vector<LL> multiply(const vector<LL>& a,int m)
{
    vector<LL>fa(a.begin(),a.end());

    int n=1,len=9*m+1;
    while(n<len) n<<=1;

    fa.resize(n);

    ntt(fa,false);

    for(int i=0;i<n;i++)
        fa[i]=cal(fa[i],m);

    ntt(fa,true);
    fa.resize(len);

    return fa;
}

int n,k;

void solve()
{
    cin>>n>>k;

    vector<LL>base(10);
    for(int i=1;i<=k;i++)
    {
        int x;
        cin>>x;
        base[x]=1;
    }

    int m=n>>1;
    vector<LL>cnt=multiply(base,m);

    LL ans=0;
    for(auto &cur:cnt)
        ans=(ans+cur*cur%MOD)%MOD;

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}