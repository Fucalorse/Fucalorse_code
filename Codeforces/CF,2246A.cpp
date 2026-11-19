#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=18,INF=2e9;

int T,n;
int p[MAX],ans[MAX];

void solve()
{
    cin>>n;

    // for(int i=1;i<=n;i++)
    //     cin>>p[i];

    for(int i=1,num=2;i<=n;i+=2,num+=2)
        ans[i]=num;
    for(int i=2,num=1;i<=n;i+=2,num+=2)
        ans[i]=num;

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}