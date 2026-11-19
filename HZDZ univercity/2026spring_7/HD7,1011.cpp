#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int t,n,k;
char s[MAX];

void solve()
{
    cin>>n>>k>>s;
    int p=__gcd(n,k);
    vector<int>f(n+3,0);
    for(int i=0;i<n/2;i++)
    {
        int j=n-i-1;
        if(s[i]!=s[j])
        {
            int u=i%p,v=j%p;
            f[min(u,v)]^=1;
        }
    }
    for(int i=0;i<p;i++)
        if(f[i])
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