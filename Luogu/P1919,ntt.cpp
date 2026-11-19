#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

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

void ntt(vector<LL> &a,bool inverse)
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

vector<LL> multiply(const vector<LL> &a,const vector<LL> &b)
{
    vector<LL>fa(a.begin(),a.end()),fb(b.begin(),b.end());

    int len=a.size()+b.size()-1,n=1;
    while(n<len) n<<=1;

    fa.resize(n),fb.resize(n);

    ntt(fa,false);
    ntt(fb,false);

    for(int i=0;i<n;i++)
        fa[i]=fa[i]*fb[i]%MOD;

    ntt(fa,true);
    fa.resize(len+1);

    for(int i=0;i<len;i++)
    {
        fa[i+1]+=fa[i]/10;
        fa[i]%=10;
        if(fa[len])
        {
            fa.push_back(0);
            ++len;
        }
    }

    while(len>0&&!fa[len]) --len;
    fa.resize(len+1);

    return fa;
}

string s,t;

void solve()
{
    cin>>s>>t;

    vector<LL>a,b;
    for(auto it=s.rbegin();it!=s.rend();++it)
        a.push_back(*it-'0');
    for(auto it=t.rbegin();it!=t.rend();++it)
        b.push_back(*it-'0');

    vector<LL>ans=multiply(a,b);
    for(auto it=ans.rbegin();it!=ans.rend();++it)
        cout<<*it;
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}