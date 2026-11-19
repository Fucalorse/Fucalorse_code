#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

int t,n;
int a[MAX],b[MAX],c[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    int cnt=0,total=0;
    double ansa,ansb,ansc;
    for(int i=1;i<=n;i++)
    {
        if(a[i]) total++;
        if(a[i]&&c[i]) cnt++;
    }
    ansa=(double)cnt/total;
    cnt=total=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]) total++;
        if(b[i]&&c[i]) cnt++;
    }
    ansb=(double)cnt/total;
    cnt=total=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&&b[i]) total++;
        if(a[i]&&b[i]&&c[i]) cnt++;
    }
    ansc=(double)cnt/total;
    
    double ans=max({ansa,ansb,ansc})*100;
    cout<<fixed<<setprecision(2)<<ans<<'%'<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}