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

vector<LL> multiply(const vector<LL>& a,const vector<LL> &b)
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

int n,m,k;
string s,t;

void solve()
{
    cin>>n>>m>>k>>s>>t;

    auto get=[&](char c)
    {
        vector<LL>good(n),ok(m);

        for(int i=0;i<m;i++)
            ok[m-i-1]=(t[i]==c);

        int cnt=0;
        for(int i=0,l=0,r=0;i<n;i++)
        {
            int lim_l=max(0,i-k),lim_r=min(n-1,i+k);

            while(r<=lim_r)
            {
                if(s[r]==c) ++cnt;
                ++r;
            }

            while(l<lim_l)
            {
                if(s[l]==c) --cnt;
                ++l;
            }

            good[i]=(cnt>=1);
        }

        vector<LL>ans=multiply(good,ok);
        return ans;
    };

    vector<LL>cnt_A=get('A'),cnt_C=get('C'),cnt_T=get('T'),cnt_G=get('G');

    int ans=0;
    for(int i=0;i<n-m+1;i++)
    {
        int pos=i+m-1;
        LL now=cnt_A[pos]+cnt_C[pos]+cnt_T[pos]+cnt_G[pos];

        if(now==m) ++ans;
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}