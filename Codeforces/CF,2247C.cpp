#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,MOD=1e9+7,INF=2e9;

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    int ca=0,cb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ca+=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        cb+=b[i];
    }

    if(cb==n&&ca!=n)
    {
        cout<<-1<<endl;
        return;
    }

    int to1=0,to0=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;

        if(a[i]) ++to0;
        else ++to1;
    }

    if(!to0&&!to1)
    {
        cout<<0<<endl;
        return;
    }

    if(to0&&to1)
    {
        if(to0&1) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else if(to0)
    {
        if(to0&1) cout<<1<<endl;
        else cout<<2<<endl;
    }
    else
    {
        if(ca==0)
        {
            cout<<-1<<endl;
            return;
        }

        cout<<2<<endl;
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