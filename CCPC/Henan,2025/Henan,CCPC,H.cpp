#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int t,n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        int s,l,r;
        cin>>s>>l>>r;
        cout<<r-l+1<<endl;
    }
    return 0;
}