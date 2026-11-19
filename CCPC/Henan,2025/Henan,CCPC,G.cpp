#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int t,n;

void solve()
{
    cin>>n;
    if(n==2) cout<<1<<' '<<2<<endl;
    else if(n==3)
    {
        cout<<1<<' '<<2<<endl;
        cout<<2<<' '<<3<<endl;
    }
    else if(n==4) cout<<-1<<endl;
    else
    {
        int p=(n+2)/3+2;
        for(int i=2;i<=p;i++)
            cout<<1<<' '<<i<<endl;
        if(n%3==1)
        {
            for(int i=p;i<n-1;i++)
                cout<<i<<' '<<i+1<<endl;
            cout<<2<<' '<<n<<endl;
        }
        else
        {
            for(int i=p;i<n;i++)
                cout<<i<<' '<<i+1<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}