#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=998244353,G=3;
const vector<pair<char,char>>h={{'a','b'},{'a','c'},{'a','d'},{'a','e'},{'a','f'},{'b','c'},{'b','d'},{'b','e'},{'b','f'},{'c','d'},{'c','e'},{'c','f'},{'d','e'},{'d','f'},{'e','f'}};

struct peach
{
    private:
        vector<int>fa,sz;
    public:
        peach(int n)
        {
            fa.assign(n+1,0);
            sz.assign(n+1,0);

            for(int i=1;i<=n;i++)
            {
                fa[i]=i;
                sz[i]=1;
            }
        }

        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }

        void combine(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;

            fa[px]=py;
            sz[py]+=sz[px];
        }

        int get(int x) { return sz[find(x)]; }
};

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

string s,t;

void solve()
{
    cin>>s>>t;

    int n=s.size(),m=t.size();  
    vector<int>mask(n-m+1);

    auto get=[&](char x,char y)
    {
        vector<LL>a(n),b(m);

        for(int i=0;i<n;i++)
            a[i]=(s[i]==x);
        for(int i=0;i<m;i++)
            b[m-i-1]=(t[i]==y);

        vector<LL>ans=multiply(a,b);
        return ans;
    };

    int len=h.size();
    for(int i=0;i<len;i++)
    {
        auto [x,y]=h[i];
        vector<LL>num1=get(x,y),num2=get(y,x);

        for(int j=0;j<n-m+1;j++)
        {
            int pos=j+m-1;
            if(num1[pos]>0||num2[pos]>0) mask[j]|=1<<i;
        }
    }

    // for(int i=0;i<=n-m;i++)
    //     cout<<mask[i]<<' ';
    // cout<<endl;

    vector<int>val(1<<15,0);

    for(int bit=0;bit<(1<<15);bit++)
    {
        peach fu(6);
        vector<bool>in_comb(7,false),vis(7,false);

        for(int k=len-1;k>=0;k--)
            if((bit>>k)&1)
            {
                auto [x,y]=h[k];
                int u=x-'a'+1,v=y-'a'+1;

                fu.combine(u,v);
                in_comb[u]=in_comb[v]=true;
            }

        int ans=0;
        for(int i=1;i<=6;i++)
            if(in_comb[i])
            {
                int fa=fu.find(i);
                if(vis[fa]) continue;

                vis[fa]=true;
                ans+=fu.get(fa)-1;
            }

        val[bit]=ans;
    }

    for(auto &bit:mask)
        cout<<val[bit]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}