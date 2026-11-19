#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090,MOD=1e9+7,LEN=5e5;

int n;
int ans[MAX];

void solve()
{
    cin>>n;

    cout<<1LL*n*(n+1)/2<<endl;
    cout<<1<<' ';
    for(int i=n;i>=2;i--)
        cout<<i<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}