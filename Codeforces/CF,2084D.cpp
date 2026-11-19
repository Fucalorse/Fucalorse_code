#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n,m,k;
int ans[MAX];

void solve()
{
    cin>>n>>m>>k;
    int x=min(n/(m+1),n-m*k);
    int dx=max(x,k);
    // cout<<x<<' '<<dx<<endl;

    for(int i=1;i<=dx*(m+1);i+=dx)
    {
        for(int j=i,p=0;j<=min(n,i+dx-1);j++,p=(p+1)%x)
            ans[j]=p;
    }
    for(int i=dx*(m+1)+1,p=0;i<=n;i++,p=(p+1)%x)
        ans[i]=p;
    
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}