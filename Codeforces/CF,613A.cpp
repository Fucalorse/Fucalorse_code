#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define pi acos(-1)
const int MAX=1e6+90,LEN=1e7,MOD=998244353;
const double INF=1e30,EPS=1e-7;

struct qwq
{
    double x,y;
}op[MAX],st;

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

double dot(const qwq &a,const qwq &b) { return a.x*b.x+a.y*b.y; }

double cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

double cal_cross(const qwq &a,const qwq &b,const qwq &c) { return cross(Vector(a,b),Vector(b,c)); }

double dis(const qwq &a,const qwq &b)
{
    double d1=fabs(a.x-b.x),d2=fabs(a.y-b.y);
    return sqrt(d1*d1+d2*d2);
}

int sgn(double x)
{
    if(x>EPS) return 1;
    else if(x<-EPS) return -1;
    else return 0;
}

int n;

void solve()
{
    cin>>n>>st.x>>st.y;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    double minn=INF,maxn=-INF;
    for(int i=1;i<=n;i++)
    {
        int j=i%n+1;

        //point--point
        double con1=dis(op[i],st);
        minn=min(minn,con1),maxn=max(maxn,con1);

        //point--segment
        qwq x=Vector(op[i],op[j]),y=Vector(op[j],st),z=Vector(op[i],st);
        if(sgn(dot(x,y))*sgn(dot(x,z))<0)
        {
            double con2=fabs(cross(x,z))/dis(op[i],op[j]);
            minn=min(minn,con2),maxn=max(maxn,con2);
        }
    }

    cout<<fixed<<setprecision(20);
    cout<<pi*(maxn*maxn-minn*minn)<<endl;
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