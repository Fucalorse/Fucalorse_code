#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

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

    if(f<0) x=-x;

    return in;
}

ostream& operator<<(ostream& out,i128 x)
{
    if(!x)
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

i128 x,y,k;

void solve()
{
    cin>>x>>y>>k;

    if(x==y)
    {
        cout<<0<<endl;
        return;
    }

    if(x*2>y)
    {
        i128 dx=y-x;
        cout<<dx*k<<endl;
        return;
    }

    int pos=y-2*x;
    i128 lim=k-1;
    if(pos>lim)
    {
        i128 ans=0;
        for(int i=0;i<=lim;i++)
        {
            i128 nx=x+i,ny=y+i;
            ans+=ny%nx;
        }
        cout<<ans<<endl;
    }
    else
    {
        i128 ans=0;
        for(int i=0;i<=pos;i++)
        {
            i128 nx=x+i,ny=y+i;
            ans+=ny%nx;
        }
        ans+=(lim-pos)*(y-x);
        cout<<ans<<endl;
    }
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