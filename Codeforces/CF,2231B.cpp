#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int t,n;
LL a[MAX],op[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]=a[i];
    }

    LL dx=0;
    for(int i=2;i<=n;i++)
        if(a[i]<a[i-1]) dx=max(dx,a[i-1]-a[i]);
    for(int i=2;i<=n;i++)
        if(op[i]<op[i-1]) op[i]+=dx;
    for(int i=2;i<=n;i++)
        if(op[i]<op[i-1])
        {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}