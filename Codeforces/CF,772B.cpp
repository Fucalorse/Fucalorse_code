#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

LL Cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL Cal_Cross(const qwq &a,const qwq &b,const qwq &c) { return Cross(Vector(a,b),Vector(b,c)); }

double Dis(const qwq &a,const qwq &b)
{
    LL d1=llabs(a.x-b.x),d2=llabs(a.y-b.y);
    return sqrt(d1*d1+d2*d2);
}

int n;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    auto cal=[&](int i,int j,int k)
    {
        LL double_S=llabs(Cal_Cross(op[i],op[j],op[k]));
        double dis=Dis(op[i],op[k]);

        double h=double_S/dis;
        return h/2;
    };

    double ans=1e30;
    for(int j=1;j<=n;j++)
    {
        int i=j==1?n:j-1,k=j%n+1;
        ans=min(ans,cal(i,j,k));
    }

    cout<<fixed<<setprecision(20);
    cout<<ans<<endl;
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