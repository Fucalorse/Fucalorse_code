#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int t,n,p;
LL s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>p>>s;
        LL now=1LL<<p;
        if((now-1)*n>=s) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}