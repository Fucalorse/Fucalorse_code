#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

int n,k;

void solve()
{
    cin>>n>>k;

    for(int i=n-k+1;i<=n;i++)
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