#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e7+90;

LL n,mod;
LL inv[MAX];

void solve()
{
    cin>>n>>mod;
    inv[1]=1;
    for(LL i=2;i<=n;i++)
    {
        LL now=(-mod/i)*inv[mod%i]%mod;
        inv[i]=(now+mod)%mod;
    }
    for(int i=1;i<=n;i++)
        cout<<inv[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}