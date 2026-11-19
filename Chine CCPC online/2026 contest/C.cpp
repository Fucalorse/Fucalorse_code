#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353;
const double EPS=1e-7,INF=1e30;

int sgn(double x)
{
    if(fabs(x)<=EPS) return 0;
    if(x<-EPS) return -1;
    else return 1;
}

LL w,x1,x2,yc,u,v;

double cal(LL x)
{
    i128 delta=(i128)4*x*x*u*u+(i128)4*((i128)v*v-u*u)*((i128)yc*yc+x*x);
    double ans=INF;

    if(u*u==v*v)
    {
        i128 p=yc*yc+x*x,q=2*x*u;
        if(q>=0) return INF;
        else return 1.00*(-p)/q;
    }

    if(delta>=0)
    {
        i128 p=2*x*u,q=2*((i128)v*v-u*u);
        double ans1=1.00*(p+sqrt((double)delta))/q,ans2=1.00*(p-sqrt((double)delta))/q;
        if(sgn(ans1)>=0) ans=min(ans,ans1);
        if(sgn(ans2)>=0) ans=min(ans,ans2);
    }

    return ans;
}

void solve()
{
    cin>>w>>x1>>x2>>yc>>u>>v;
    cout<<fixed<<setprecision(20);

    bool side=false;
    if(x1<=0&&x2<=0&&u<=0) side=true;
    if(x1>=0&&x2>=0&&u>=0) side=true;

    if(side)
    {
        double ans=1.00*w/v;
        cout<<ans<<endl;
    }
    else
    {
        double cost_middle=1.00*yc/v;
        double L=x1+u*cost_middle,R=x2+u*cost_middle;
        if(sgn(L)*sgn(R)>=0)
        {
            double ans=1.00*w/v;
            cout<<ans<<endl;
        }
        else
        {
            double base=min(cal(x1),cal(x2)),other=1.00*(w-yc)/v;
            cout<<base+other<<endl;
        }
    }
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