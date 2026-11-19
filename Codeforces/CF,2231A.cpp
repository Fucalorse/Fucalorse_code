#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int t,n;
int ans[MAX];

void solve()
{
    cin>>n;
    queue<int>q[2];
    for(int i=1;i<=n;i++)
        if(i&1) q[1].push(i);
    for(int i=n;i<=2*n;i++)
        if(i%2==0) q[0].push(i);
    
    for(int i=1;i<=n;i++)
        if(i&1)
        {
            ans[i]=q[1].front();
            q[1].pop();
        }
        else
        {
            ans[i]=q[0].front();
            q[0].pop();
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