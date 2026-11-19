#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define endl '\n'

int n;
LL f[20];
LL a,b;

bool dis(const LL &x)
{
    for(int i=n;i>=1;i--)
    {
        LL now=x/f[i];
        // cout<<now<<' ';
        if(now%(n-i+1)!=0) return false;
    }
    return true;
}

int main()
{
    f[1]=1;
    for(int i=2;i<=16;i++)
        f[i]=f[i-1]*10;
    cin>>n>>a>>b;
    bool g=false;
    for(LL i=max(a,f[n]);i<=min(b,f[n+1]);i++)
        if(dis(i)) cout<<i<<endl,g=true;
    if(!g) cout<<"No Solution"<<endl;
    return 0;
}