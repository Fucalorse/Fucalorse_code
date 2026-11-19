#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

LL m,r,c;

void solve()
{
    cin>>m>>r>>c;

    if(c<=m)
    {
        cout<<fixed<<setprecision(20);
        cout<<1.00<<endl;
        return;
    }

    //ghost + wait
    double con1=1.00*m/c;

    //ghost + restore + wait
    double con2=-1e30;
    LL cnt=c/(m+r)+1;
    for(LL d=1;d<=cnt;d++)
    {
        LL fire=d*m+m,total=max(c,d*(m+r)+m);
        con2=max(con2,1.00*fire/total);
    }

    cout<<fixed<<setprecision(20);
    cout<<max(con1,con2)<<endl;
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