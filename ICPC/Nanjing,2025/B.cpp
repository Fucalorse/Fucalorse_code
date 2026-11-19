#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
};

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

i128 cross(const qwq &a,const qwq &b) { return (i128)a.x*b.y-(i128)a.y*b.x; }

i128 cal_cross(const qwq &a,const qwq &b,const qwq &c) { return cross(Vector(a,b),Vector(a,c)); }

i128 dot(const qwq &a,const qwq &b) { return (i128)a.x*b.x+(i128)a.y*b.y; }

int n;
LL a[MAX],b[MAX],c[MAX];

void solve()
{
    cin>>n;

    vector<qwq>op;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]||b[i]) op.push_back({a[i],b[i]});
    }

    auto half=[&](const qwq &now)
    {
        if(now.y>0||(now.y==0&&now.x>=0)) return 0;
        else return 1;
    };

    sort(op.begin(),op.end(),[&](const qwq &a,const qwq &b){
        int ha=half(a),hb=half(b);
        if(ha!=hb) return ha<hb;
        else
        {
            i128 now=cross(a,b);
            return now>0;
        }
    });

    int len=op.size();
    for(int i=0;i<len;i++)
        op.push_back(op[i]);

    auto check=[&](const qwq &a,const qwq &b)
    {
        i128 now=cross(a,b);
        return (now>0)||(now==0&&dot(a,b)>0);
    };

    int ans=0;
    for(int l=0,r=0;l<len;++l)
    {
        while(r<l+len&&check(op[l],op[r])) ++r;
        ans=max(ans,r-l);
    }

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