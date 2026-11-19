#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T;
LL x,y;

void solve()
{
    cin>>x>>y;
    if(x==y) cout<<-1<<endl;
    else
    {
        LL k=log2(max(x,y))+1;
        cout<<(1<<k)-max(x,y)<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}