#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
#define double long double
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;
const double EPS=1e-6;

template <typename T>
T qpow(T a,LL p)
{
    T ans=1;
    while(p)
    {
        if(p&1) ans=ans*a;
        a=a*a;
        p>>=1;
    }
    return ans;
}

int sgn(double x)
{
    if(fabs(x)<=EPS) return 0;
    else if(x>EPS) return 1;
    else return -1;
}

void solve()
{
    double x0,y0,x1,x2,y1,y2;
    double v0,v0_y,vy1,vy2,v1,v2;

    cin>>x0>>y0>>v0>>v0_y;
    cin>>y1>>y2>>vy1>>vy2;
    cin>>x1>>x2>>v1>>v2;

    cout<<fixed<<setprecision(20);
    double T=1.00*(y2-y1)/(vy1+vy2),now=0.00,ansY=y2-T*vy2;

    if(sgn(v1)==0&&sgn(v2)==0)
    {
        double cost_round=2*(x2-x1)/fabs(v0);
        LL k=T/cost_round;
        double rest=T-cost_round*k;

        if(sgn(v0)<0)
        {
            v0=fabs(v0);
            if(sgn((x0-x1)/v0-rest)<=0)
            {
                rest-=(x0-x1)/v0;
                x0=x1;
            
                if(sgn((x2-x1)/v0-rest)<=0)
                {
                    rest-=(x2-x1)/v0;
                    x0=x2;
                    x0-=v0*rest;
                }
                else x0+=rest*v0;
            }
            else x0-=rest*v0;

            cout<<x0<<' '<<ansY<<endl;
        }
        else
        {
            if(sgn((x2-x0)/v0-rest)<=0) 
            {
                rest-=(x2-x0)/v0;
                x0=x2;

                if(sgn((x2-x1)/v0-rest)<=0)
                {
                    rest-=(x2-x1)/v0;
                    x0=x1;
                    x0+=v0*rest;
                }
                else x0-=rest*v0;
            }
            else x0+=rest*v0;

            cout<<x0<<' '<<ansY<<endl;
        }
        return;
    }

    if(sgn(v0)<0)
    {
        v0=fabs(v0);
        if(sgn(v1-v0)>=0)
        {
            cout<<x0-v0*T<<' '<<ansY<<endl;
            return;
        }

        now+=(x0-x1)/(v0-v1);
        if(sgn(now-T)>=0)
        {
            cout<<x0-v0*T<<' '<<ansY<<endl;
            return;
        }
        x0=x1=x1-now*v1;
        x2+=now*v2;
    }
    else
    {
        if(sgn(v2-v0)>=0)
        {
            cout<<x0+v0*T<<' '<<ansY<<endl;
            return;
        }
        
        now+=(x2-x0)/(v0-v2);
        if(sgn(now-T)>=0)
        {
            cout<<x0+v0*T<<' '<<ansY<<endl;
            return;
        }
        x0=x2=x2+now*v2;
        x1-=now*v1;

        if(sgn(v1-v0)>=0)
        {
            cout<<x0-v0*(T-now)<<' '<<ansY<<endl;
            return;
        }

        double pre=now;
        now+=(x0-x1)/(v0-v1);
        if(sgn(now-T)>=0)
        {
            cout<<x0-v0*(T-pre)<<' '<<ansY<<endl;
            return;
        }
        x0=x1=x1-(now-pre)*v1;
        x2+=(now-pre)*v2;
    }

    if(sgn(v2-v0)>=0)
    {
        cout<<x0+(T-now)*v0<<' '<<ansY<<endl;
        return;
    }

    double D0=x2-x1,q=(v0+v2)*(v0+v1)/(v0-v1)/(v0-v2),DT=D0+(v1+v2)*(T-now);
    LL k=log(DT/D0)/log(q);

    double dT=(D0*qpow(q,k)-D0)/(v1+v2),rest=T-(now+dT);
    x0=x1=x1-dT*v1,x2+=dT*v2;
    double cost=(x2-x0)/(v0-v2);

    if(sgn(cost-rest)>=0) cout<<x0+rest*v0<<' '<<ansY<<endl;
    else
    {
        x0+=cost*v0;
        rest-=cost;
        x0-=rest*v0;
        cout<<x0<<' '<<ansY<<endl;
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