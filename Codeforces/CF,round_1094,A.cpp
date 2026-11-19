#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int t,n;
int a[MAX];

void solve()
{
    cin>>n;
    bool f=false;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==100) f=true;
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}