#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2090,LEN=32,G=3,MOD=998244353,INF=2e9;

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

struct discrete
{
    private:
        vector<LL>num;
    public:
        void add(LL n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(LL n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return (int)num.size(); }
};

struct fucalorse
{
    private:
        int n;
        vector<LL>op;
    public:
        fucalorse(int _n) { n=_n,op.assign(n+3,0LL); }

        void update(int pos,LL k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                op[i]=(op[i]+k)%MOD;
        }

        LL query(int pos)
        {
            LL ans=0;
            for(int i=pos;i;i-=i&-i)
                ans=(ans+op[i])%MOD;
            return ans;
        }
};

int n;
LL a[MAX],b[MAX],num[MAX][MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    if(n==1)
    {
        cout<<0<<endl;
        return;
    }

    discrete dis;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            num[i][j]=a[i]*b[j];
            dis.add(num[i][j]);
        }

    dis.create();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            num[i][j]=dis.find(num[i][j]);

    LL ans=0;
    fucalorse fu(dis.size());
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
            ans=(ans+fu.query(num[i][j]-1))%MOD;

        for(int j=1;j<=n;j++)
            fu.update(num[i][j],1LL);
    }

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j]) ans=(ans-n+MOD)%MOD;

    cout<<ans*qpow(1LL*n*(n-1),MOD-2)%MOD<<endl;
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