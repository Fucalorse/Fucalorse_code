#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    LL x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        else return y<a.y;
    }
}op[MAX];

qwq Vector(const qwq &a,const qwq &b) { return {b.x-a.x,b.y-a.y}; }

LL Cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL Cal_Cross(const qwq &a,const qwq &b,const qwq &c) { return Cross(Vector(a,b),Vector(b,c)); }

int n;

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>op[i].x>>op[i].y;

    // for(int i=1;i<=n;i++)
    //     cout<<op[i].x<<' '<<op[i].y<<endl;

    int ans=0;
    for(int i=2;i<=n-1;i++)
        if(Cal_Cross(op[i-1],op[i],op[i+1])>0) ++ans;

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