#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    int maxn=-inf,minn=inf;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        minn=min(minn,a[i]);
    }

    cout<<(maxn-minn+1)/2<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}