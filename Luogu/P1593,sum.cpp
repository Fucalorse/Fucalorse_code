#include <bits/stdc++.h>
using namespace std;

const int mod=9901;

int cal(int a,int p)
{
    int ans=1;
    while(p)
    {
        if(p&1) ans=ans*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return ans;
}

int sum(int a,int p)
{
    if(a%mod==1) return p+1;
    return (cal(a%mod,p+1)-1+mod)%mod*cal((a-1)%mod,mod-2)%mod;
}

int main()
{
    int a,b;
    cin>>a>>b;
    int total=1;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i!=0) continue;
        int cnt=0;
        while(a%i==0) a/=i,cnt++;
        total=total*sum(i,cnt*b)%mod;
    }
    if(a>1) total=total*sum(a,b)%mod;
    cout<<total<<endl;
    return 0;
}