#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=1e6,MOD=998244353,INF=2e9;

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

LL qpow(LL a,int p)
{
    LL ans=1;

    while(p)
    {
        if(p&1) ans=ans*a;
        a=a*a;
        p>>=1;
    }

    return ans;
}

int n,t;
LL a[MAX],b[MAX];

LL gcd(LL a,LL b)
{
    if(!b) return a;
    return gcd(b,a%b);
}

LL cal(int x)
{
    LL ans=0;

    for(int i=1;i<=n;i++)
    {
        LL now=a[i];
        for(int j=1;j<=x;j++)
            now*=b[i];

        // cout<<now<<' ';
        ans+=now;
    }

    return ans;
}

void solve()
{
    cin>>n>>t;

    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i];

    if(!t)
    {
        cout<<0<<endl;
        return;
    }

    for(int i=1;i<t;i++)
        if(cal(i)!=0LL)
        {
            cout<<"infinity"<<endl;
            return;
        }
    
    LL now=cal(t);
    // cout<<now<<endl;
    if(now!=0LL)
    {
        LL r=gcd(now,t);
        if(t%2==0) cout<<'-';

        LL p=now/r,q=t/r;

        cout<<p;
        if(q!=1) cout<<'/'<<q;
        cout<<endl;
    }
    else cout<<0<<endl;
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