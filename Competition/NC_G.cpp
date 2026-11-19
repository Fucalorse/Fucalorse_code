#include <bits/stdc++.h>
using namespace std;

int t,n;

int cal(const int &x)
{
    int m=x/3,rest=x%3;
    if(!rest) return m;
    if(rest==2&&m>=1) return m;
    if(rest==1&&m>=2) return m-1;
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<cal(n)<<'\n';
    }
    return 0;
}