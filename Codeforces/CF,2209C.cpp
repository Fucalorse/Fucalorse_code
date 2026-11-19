#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

int ask(int i,int j)
{
    cout<<'?'<<' '<<i<<' '<<j<<endl<<flush;
    int col;
    cin>>col;
    return col;
}

int n;

void solve()
{
    cin>>n;

    int m=n<<1;
    queue<int>q[2];
    for(int i=1;i<=m;i++)
        q[i&1].push(i);

    for(int round=1;round<=n-2;++round)
    {
        array<int,2>c;
        for(int i=0;i<=1;i++)
        {
            c[i]=q[i].front();
            q[i].pop();
        }

        int col=ask(c[0],c[1]);
        if(col==1)
        {
            cout<<'!'<<' '<<c[0]<<endl<<flush;
            return;
        }
    }

    array<int,2>x,y;
    for(int i=0;i<=1;i++)
    {
        x[i]=q[0].front();q[0].pop();
        y[i]=q[1].front();q[1].pop();
    }

    int c1=ask(x[0],x[1]),c2=ask(x[0],y[0]),c3=ask(x[1],y[0]),ans;
    if(c1) ans=x[0];
    else if(c2) ans=x[0];
    else if(c3) ans=x[1];
    else ans=y[1];

    cout<<'!'<<' '<<ans<<endl<<flush;
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