#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int t;
LL n;

LL cal(LL x)
{
    LL ans=1e9;
    while(x)
    {
        LL now=x%10;
        ans=min(ans,(7-now+10)%10);
        x/=10;
    }
    return min(ans,7LL);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    for(int k=1;k<=t;k++)
    {
        cin>>n;
        for(int i=0;i<=7;i++)
            if(cal(n-i)<=i)
            {
                cout<<i<<endl;
                break;
            }
    }
    return 0;
}