#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=2e5,G=3,MOD=1e9+7,INF=2e9;
const LL LINF=1e18;

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

int n;
int a[MAX];
LL fac[MAX],inv[MAX];

void create()
{
    fac[0]=1;
    for(int i=1;i<=LEN;i++)
        fac[i]=fac[i-1]*i%MOD;

    inv[LEN]=qpow(fac[LEN],MOD-2);
    for(int i=LEN-1;i>=0;i--)
        inv[i]=inv[i+1]*(i+1)%MOD;
}

void solve()
{
    cin>>n;

    LL ans=0;
    set<int>st;
    int left=n>>1,right=(n-1)>>1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }

    auto update=[&](int d)
    {
        set<int>f,g;
        bool ok=true;

        for(int i=a[n]-d;i;i-=d)
        {
            if(st.count(i))
            {
                f.insert(i);
                if((int)f.size()==right) break;
            }
            else
            {
                ok=false;
                break;
            }
        }

        for(int i=0;i<a[n];i+=d)
        {
            if(st.count(i))
            {
                g.insert(i);
                if((int)g.size()==left) break;
            }
            else
            {
                ok=false;
                break;
            }
        }

        if(ok)
        {
            LL con;
            bool same=false;

            for(auto &cur:f)
                if(g.count(cur))
                {
                    same=true;
                    break;
                }

            if(same||(int)(f.size()+g.size())!=n-1)  con=0;
            else con=fac[f.size()-1]*fac[g.size()]%MOD;

            ans=(ans+con)%MOD;
        }
    };

    int q=(n-1)/2;
    update(a[2]);
    if((a[n]-a[2])%q==0)
    {
        int d=(a[n]-a[2])/q;
        if(d!=a[2]) update(d);
    }

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