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
        int dx=n&1?0:2;
        bitset<32>bit=n;
        cout<<bit.count()-1+dx<<endl;
    }
    return 0;
}