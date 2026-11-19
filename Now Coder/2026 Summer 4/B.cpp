#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

LL p;

void solve()
{
    cin>>p;

    if(p==2)
    {
        cout<<12<<' '<<1<<' '<<71<<endl;
        return;
    }
    else if(p==3)
    {
        cout<<4<<' '<<1<<' '<<13<<endl;
        return;
    }
    else
    {
        LL now=1.00*(1+sqrt(1+4*p))/2;++now;
        LL x1=now,x2=now,q=x1*x1-p;
        cout<<x1<<' '<<x2<<' '<<q<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}