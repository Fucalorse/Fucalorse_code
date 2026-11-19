#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(n&1)
    {
        cout<<"NO"<<endl;
        return;
    }

    int l=-INF,r=INF;

    auto update=[&](int x,int y)
    {
        l=max(l,y+1),r=min(r,x-1);
    };

    for(int i=1;i<=n;i+=2)
    {
        if(a[i]<=a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }

        update(a[i],a[i+1]);
    }

    if(l>r) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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