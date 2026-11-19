#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    sort(a+1,a+n+1,greater<int>());

    for(int i=3;i<=n;i++)
        if(a[i]!=a[i-2]%a[i-1])
        {
            cout<<-1<<endl;
            return;
        }

    cout<<a[1]<<' '<<a[2]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}