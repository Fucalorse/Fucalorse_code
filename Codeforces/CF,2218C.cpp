#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=26,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=0,now=3*n-1;i<n;i++,now-=2)
    {
        int x=3*i+1,y=3*i+2,z=3*i+3;
        a[x]=now,a[y]=now+1,a[z]=i+1;
    }

    for(int i=1;i<=n*3;i++)
        cout<<a[i]<<' ';
    cout<<endl;
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