#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct qwq
{
    int id;
    LL val;
    bool operator<(const qwq &a)const { return val>a.val; }
}op[MAX];

int t,n;
int ans[MAX];
LL a[MAX],f[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
        op[i]={i,f[i-1]};
    sort(op+1,op+n+1);
    for(int i=1;i<=n;i++)
        ans[op[i].id]=i;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}