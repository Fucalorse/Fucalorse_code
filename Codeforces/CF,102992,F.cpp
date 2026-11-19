#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const double EPS=1e-7;

int n,m,p;

int sgn(double x)
{
    if(fabs(x)<=EPS) return 0;

    if(x<-EPS) return -1;
    else return 1;
}

void solve()
{
    cin>>n>>m>>p;

    if(p==10000)
    {
        double ans=n+m;
        cout<<fixed<<setprecision(20);
        cout<<ans<<endl;
        return;
    }

    double win=1.00*p/10000,lose=1-win,C=log(lose);

    auto cal_derivative=[&](LL x)
    {
        double now=n+pow(lose,x)*(n*C*x+m*C-n);
        return now;
    };

    auto cal_f=[&](LL x)
    {
        double p=n*x+m,q=1-pow(lose,x);
        return 1.00*p/q;
    };

    LL l=1,r=1;
    while(sgn(cal_derivative(r))<0) r<<=1;

    while(l<=r)
    {
        LL mid=(l+r)>>1;
        double now=cal_derivative(mid);

        if(sgn(now)<0) l=mid+1;
        else r=mid-1;
    }

    double ans=cal_f(l);
    for(LL k=max(1LL,l-1);k<=l+1;k++)
        ans=min(ans,cal_f(k));

    cout<<fixed<<setprecision(20);
    cout<<ans<<endl;
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