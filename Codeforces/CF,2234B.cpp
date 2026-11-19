#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const vector<int>num={0,1,2,3,4,5,6,7,8,9,22,11};

int T;
LL n;

void solve()
{
    cin>>n;

    int r=n%12;
    if(num[r]<=n) cout<<num[r]<<' '<<n-num[r]<<endl;
    else cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}