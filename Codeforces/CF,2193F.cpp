#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

struct qwq
{
    LL x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        return y<a.y;
    }
}A,B,op[MAX];

int n;

void solve()
{
    cin>>n>>A.x>>A.y>>B.x>>B.y;

    map<LL,LL>L,R;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x;
        L[op[i].x]=LINF;
        R[op[i].x]=-LINF;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].y;
        L[op[i].x]=min(L[op[i].x],op[i].y);
        R[op[i].x]=max(R[op[i].x],op[i].y);
    }
    L[B.x]=B.y,R[B.x]=B.y;

    vector<LL>dp(2,0LL),ndp(2,0LL);
    LL up=A.y,down=A.y;
    for(auto &[x,_cur]:L)
    {
        LL nup=R[x],ndown=_cur;
        fill(ndp.begin(),ndp.end(),LINF);

        auto update=[&](LL cur,LL val)->void
        {
            ndp[0]=min(ndp[0],val+llabs(cur-nup)+nup-ndown);
            ndp[1]=min(ndp[1],val+llabs(cur-ndown)+nup-ndown);
        };
        update(up,dp[1]);
        update(down,dp[0]);

        up=nup,down=ndown;
        swap(dp,ndp);
    }

    cout<<min(dp[0],dp[1])+B.x-A.x<<endl;
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