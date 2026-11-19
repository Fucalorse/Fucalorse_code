#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int mod=998244353;

int t;
LL x,y;

LL cal(LL a,LL p)
{
    LL ans=1;
    while(p)
    {
        if(p&1) ans=(ans*a)%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        cout<<cal(2,x-y-1)*(y+1)%mod<<'\n';
    }
    return 0;
}