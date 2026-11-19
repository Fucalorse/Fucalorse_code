#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
#define i128 __int128
const int MAX=1e6+90,LEN=64,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

template <typename T>
T qpow(T a,LL p)
{
    T ans=1;
    while(p)
    {
        if(p&1) ans=ans*a;
        a=a*a;
        p>>=1;
    }
    return ans;
}

ULL a,b;

void solve()
{
    cin>>a>>b;

    if(a%2==0)
    {
        for(int k=0;k<=LEN;k++)
            if(qpow(a,k)==b)
            {
                cout<<k<<endl;
                return;
            }

        cout<<"broken message"<<endl;
    }
    else
    {
        if(b%2==0)
        {
            cout<<"broken message"<<endl;
            return;
        }

        ULL x=0,cur=1,u=a;
        for(int k=0;u!=1;k++)
        {
            int pos=__builtin_ctzll(u-1);
            if(((cur^b)>>pos)&1)
            {
                x+=1ULL<<k;
                cur*=u;
            }
            u*=u;
        }

        if(cur==b) cout<<x<<endl;
        else cout<<"broken message"<<endl;
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