#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i128 __int128
#define LD long double
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

istream& operator>>(istream& in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;
    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    if(f==-1) x=-x;

    return in;
}

ostream& operator<<(ostream& out,i128 x)
{
    if(x==0)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

int T,n;
i128 a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    i128 s=0,sx=0,sy=0,square=0;
    for(int i=1;i<=n;i++)
    {
        s+=i*a[i];
        sx+=i;
        sy+=a[i];
        square+=(i128)i*i;
    }

    i128 up=n*s-sx*sy,down=n*square-sx*sx;
    LD A=(LD)up/down;
    LD B=(1.00*sy-A*sx)/(LD)n;

    LD ans=0.00;
    for(int i=1;i<=n;i++)
    {
        LD now=a[i]-(A*i+B);
        ans+=now*now;
    }

    cout<<fixed<<setprecision(20);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}