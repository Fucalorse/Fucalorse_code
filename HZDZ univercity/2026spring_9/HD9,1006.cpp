#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=9e18;

int t;
LL n,k,u,v;

void solve()
{
    cin>>n>>k>>u>>v;
    LL prex=k-1,prey=n-k,ans=prex*u+prey*v,x,y;

    x=prex&1,y=prex/2+prey;
    ans=min(ans,x*u+y*v);
    if((prex&1)&&y>=2)
    {
        x--,y--;
        ans=min(ans,x*u+y*v);
    }

    x=prey/2+prex,y=prey&1;
    ans=min(ans,x*u+y*v);
    // cout<<ans<<' ';
    if((prey&1)&&x>=2)
    {
        x--,y--;
        ans=min(ans,x*u+y*v);
    }

    LL now=((prex-prey)%3+3)%3;
    if(now==0)
    {
        if((prex==0&&prey==0)||(prex==1&&prey==1)) ans=min(ans,u*prex+v*prey);
        else
        {
            ans=min(ans,u+v);
            if(prex!=0||prey!=3) ans=min(ans,3*u+0*v);
            if(prex!=3||prey!=0) ans=min(ans,0*u+3*v);
        }
    }
    else if(now==1)
    {
        ans=min(ans,u);
        if(prex!=1||prey!=0) ans=min(ans,2*v);
    }
    else
    {
        ans=min(ans,v);
        if(prex!=0||prey!=1) ans=min(ans,2*u);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}