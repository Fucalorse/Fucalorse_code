#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;
    
    vector<int>pre(n+1,INF);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=min(pre[i-1],a[i]);
    }

    int sum=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=min(a[i],pre[i]);
        sum+=a[i];
    }

    cout<<sum<<endl;
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