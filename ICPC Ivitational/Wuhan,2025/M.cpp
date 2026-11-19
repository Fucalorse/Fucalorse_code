#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=2e5,MOD=998244353,INF=2e9;
const double EPS=1e-10;

struct qwq
{
    double x,y,z;
};

int r;
int a,b,c;
int u,v,w;
int x,y,z;

double dis(qwq a)
{
    double ans=sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    return ans;
}

qwq cal_point(int x,int y,int z)
{
    double len=dis(qwq{(double)x,(double)y,(double)z});
    qwq ans;

    ans.x=x/len;
    ans.y=y/len;
    ans.z=z/len;

    return ans;
}

qwq cross(qwq a,qwq b)
{
    qwq ans;
    ans.x=a.y*b.z-b.y*a.z;
    ans.y=-(a.x*b.z-b.x*a.z);
    ans.z=a.x*b.y-b.x*a.y;

    return ans;
}

double dot(qwq a,qwq b) { return a.x*b.x+a.y*b.y+a.z*b.z; }

bool same_dir(qwq a,qwq b)
{
    double lena=dis(a),lenb=dis(b);

    if(lena<1e-12||lenb<1e-12) return true;

    double ans=dot(a,b)/(lena*lenb);
    return ans>=-1e-12;
}

void solve()
{
    cin>>r;
    cin>>a>>b>>c;
    cin>>u>>v>>w;
    cin>>x>>y>>z;

    qwq A=cal_point(a,b,c),U=cal_point(u,v,w),V=cal_point(x,y,z);

    qwq n=cross(U,V);
    double lambda=dot(A,n)/dot(n,n);

    qwq W;
    W.x=A.x-lambda*n.x;
    W.y=A.y-lambda*n.y;
    W.z=A.z-lambda*n.z;

    double len=dis(W);

    if(len<EPS)
    {
        cout<<fixed<<setprecision(20);
        cout<<asin(1)*r<<endl;
        return;
    }

    W.x=W.x/len;
    W.y=W.y/len;
    W.z=W.z/len;

    double ans;
    qwq U_V=cross(U,V),U_W=cross(U,W),W_V=cross(W,V);

    auto cal_ans=[&](qwq a,qwq b)
    {
        double now=dot(a,b)/dis(a)/dis(b);
        now=clamp(now,-1.0,1.0);
        double theta=acos(now);
        return (double)theta*r;
    };

    if(same_dir(U_V,U_W)&&same_dir(U_V,W_V)) ans=cal_ans(W,A);
    else
    {
        double ans1=cal_ans(A,U),ans2=cal_ans(A,V);
        ans=min(ans1,ans2);
    }

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