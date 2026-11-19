#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
#define pi acos(-1)
const int MAX=1e6+90,LEN=1e7,MOD=998244353,INF=2e9;
const double EPS=1e-7;

struct qwq
{
    LL x,y;
}op[MAX];

LL cross(const qwq &a,const qwq &b) { return a.x*b.y-a.y*b.x; }

LL dot(const qwq &a,const qwq &b) { return a.x*b.x+a.y*b.y; }

int n;

void solve()
{
    cin>>n;

    vector<int>id(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;
        id[i]=i;
    }

    auto half=[&](const qwq &a) { return a.y<0||(a.y==0&&a.x<0); };

    sort(id.begin()+1,id.end(),[&](const int &i,const int &j){
        const qwq &a=op[i],&b=op[j];

        int ha=half(a),hb=half(b);
        if(ha!=hb) return ha<hb;
        else return cross(a,b)>0;
    });

    // for(int i=1;i<=n;i++)
    //     cout<<id[i]<<' ';
    // cout<<endl;

    bool first=true;
    pair<int,int>ans;
    pair<LL,LL>pre;

    auto check=[&](LL ca,LL da,LL cb,LL db)
    {
        LL now=ca*db-cb*da;
        return now>0;
    };

    for(int i=1;i<=n;i++)
    {
        int x=id[i],y=id[i%n+1];
        LL dc=llabs(cross(op[x],op[y])),dt=dot(op[x],op[y]);

        if(first||check(pre.first,pre.second,dc,dt))
        {
            pre={dc,dt};
            ans={x,y};
            first=false;
        }
    }

    cout<<ans.first<<' '<<ans.second<<endl;
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