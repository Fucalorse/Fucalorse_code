#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define i128 __int128
#define LL long long
const int MAX=2e5+90;

istream& operator>>(istream &in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;
    for(size_t i=0;i<s.size();i++)
    {
        if(s[i]=='-') f=-1;
        else x=x*10+s[i]-'0';
    }

    if(f==-1) x=-x;

    return in;
}

ostream& operator<<(ostream &out,i128 x)
{
    if(x==0)
    {
        out<<'0';
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

i128 n,k,a,b;

i128 gcd(i128 a,i128 b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

bool check(const i128 mid)
{
    i128 ed=sqrt((long double)2*k),ans=0;

    for(i128 d=1;d<=ed;d++)
    {
        i128 now=(mid-a*d*d-2*b*d)/(2*a*d);
        i128 dx=max((i128)0,min(n-d,now));
        ans+=dx;
        if(ans>=k) return true;
    }

    return ans>=k;
}

void solve()
{
    cin>>n>>k>>a>>b;
    //l->0  r->(n-1)*delta(h)
    i128 l=0,r=(n-1)*(a*(1+n)+2*b);
    while(l<=r)
    {
        i128 mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }

    i128 dx=gcd(l,a);
    cout<<l/dx<<' '<<a/dx<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}