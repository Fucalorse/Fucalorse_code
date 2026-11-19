#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

int T;
double r,x,y,d;

void solve()
{
    cin>>r>>x>>y>>d;

    double len=sqrt(pow(x,2)+pow(y,2));
    double theta=asin((d-len)/r)+asin((d+len)/r);

    cout<<fixed<<setprecision(20);
    cout<<r*theta<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}