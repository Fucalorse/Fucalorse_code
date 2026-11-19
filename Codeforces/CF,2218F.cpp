#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,x,y;

void solve()
{
    cin>>x>>y;
    if((x+y)&1) y--;
    else x--;
    if(x<0||y<0||x>y)
    {
        cout<<"NO"<<endl;
        return;
    }
    y-=x;
    int now=2;
    cout<<"YES"<<endl;
    for(int i=1;i<=x;i++,now+=2)
    {
        cout<<1<<' '<<now<<endl;
        cout<<now<<' '<<now+1<<endl;
    }
    for(int i=1;i<=y;i++,now++)
        cout<<1<<' '<<now<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}