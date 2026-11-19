#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=26,MOD=998244353,INF=2e9;

int a[MAX];

void solve()
{
    int sum=0,maxn=-INF;
    for(int i=1;i<=7;i++)
    {
        cin>>a[i];
        sum+=a[i];
        maxn=max(maxn,a[i]);
    }

    cout<<-(sum-maxn)+maxn<<endl;
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