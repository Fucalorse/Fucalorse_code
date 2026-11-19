#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
#define pi acos(-1)
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct qwq
{
    LL x,y;
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return qwq{b.x-a.x,b.y-a.y}; }
i128 cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }
i128 cal_cross(const qwq &a,const qwq &b,const qwq &c) { return cross(Vector(a,b),Vector(a,c)); }
i128 dot(const qwq &a,const qwq &b) { return a.x*b.x+a.y*b.y; }
double dist(const qwq &a,const qwq &b)
{
    LL dx=llabs(a.x-b.x),dy=llabs(a.y-b.y);
    return sqrt(dx*dx+dy*dy);
}

int n,k;
double angle[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    auto half=[&](const qwq &now)->int
    {
        if(now.y>0||(now.y==0&&now.x>0)) return 0;
        else return 1;
    };

    sort(op+1,op+n+1,[&](const qwq &a,const qwq &b){
        int ha=half(a),hb=half(b);
        if(ha!=hb) return ha<hb;
        else return cross(a,b)>0;
    });

    int m=n<<1;
    for(int i=1;i<=n;i++)
    {
        angle[i]=atan2(op[i].y,op[i].x);
        if(angle[i]<0) angle[i]+=2*pi;
        op[i+n]=op[i];
        angle[i+n]=angle[i]+2*pi;
    }

    double maxn=0;
    for(int l=1,r=k+1;l<=m&&r<=m;l++,r++)
    {
        double now=fabs(angle[l]-angle[r]);
        maxn=max(maxn,now);
    }

    cout<<fixed<<setprecision(20)<<maxn<<endl;
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