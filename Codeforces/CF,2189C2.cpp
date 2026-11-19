#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int ans[MAX];

void solve()
{
    cin>>n;
    int bit=log2(n);
    if((1<<bit)==n)
    {
        cout<<-1<<endl;
        return;
    }
    for(int i=2;i<=n-1;i+=2)
        ans[i]=i+1,ans[i+1]=i;
    if(n&1) ans[1]=n-1,ans[n]=1;
    else
    {
        ans[1]=n,ans[n]=1;
        int now=n-(1<<bit);
        swap(ans[now],ans[1]);
    }
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