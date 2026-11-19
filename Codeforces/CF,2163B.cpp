#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int a[MAX];
char s[MAX];

void solve()
{
    cin>>n;
    int l,r;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1) l=i;
        if(a[i]==n) r=i;
    }
    cin>>(s+1);
    if(s[1]=='1'||s[n]=='1'||s[l]=='1'||s[r]=='1')
    {
        cout<<-1<<endl;
        return;
    }
    cout<<5<<endl;
    cout<<1<<' '<<l<<endl;
    cout<<1<<' '<<r<<endl;
    cout<<min(l,r)<<' '<<max(l,r)<<endl;
    cout<<l<<' '<<n<<endl;
    cout<<r<<' '<<n<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}