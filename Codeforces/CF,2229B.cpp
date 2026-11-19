#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int T,n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
        if(a[i]>b[i]) swap(a[i],b[i]);

    int maxn=-inf;
    LL total=0;
    for(int i=1;i<=n;i++)
    {
        total+=b[i];
        maxn=max(maxn,a[i]);
    }

    cout<<total+maxn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}