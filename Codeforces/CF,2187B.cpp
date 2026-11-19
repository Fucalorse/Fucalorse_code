#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=30;

int t;
LL x,y;

void solve()
{
    cin>>x>>y;
    if((x&y)==0)
    {
        cout<<x<<' '<<y<<endl;
        return;
    }
    LL p=x,q=y,minn=1e18;
    auto update=[&](LL a,LL b)
    {
        if((a&b)==0&&llabs(x-a)+llabs(y-b)<minn)
        {
            minn=llabs(x-a)+llabs(y-b);
            p=a,q=b;
        }
    };
    for(int i=LEN;i>=0;i--)
        if(((x&y)>>i)&1)
        {
            update((x>>i<<i)+(1LL<<i),y);
            update(x,(y>>i<<i)+(1LL<<i));
            update(x>>i<<i,(y>>i<<i)-1);
            update((x>>i<<i)-1,y>>i<<i);
        }
    cout<<p<<' '<<q<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}