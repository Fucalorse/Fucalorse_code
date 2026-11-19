#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        LL ans=0;
        for(int k=1;(1<<k)<=n;k++)
        {
            LL s=n>>k;
            ans+=s*(n+1)-(1<<k)*(1+s)*s/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}