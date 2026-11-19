#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=26,MOD=998244353,INF=2e9;

int n,m;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];

    if(n<2*m)
    {
        cout<<"NO"<<endl;
        return;
    }

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    for(int i=n,j=m;i>=1&&j>=1;i--,j--)
        if(b[j]>a[i])
        {
            cout<<"NO"<<endl;
            return;
        }

    for(int i=1,j=1;i<=n&&j<=m;i++,j++)
        if(b[j]<a[i])
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

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}