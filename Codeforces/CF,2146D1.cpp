#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,l,r;
int ans[MAX];
bool vis[MAX];

void clear()
{
    for(int i=l;i<=r;i++)
    {
        ans[i]=0;
        vis[i]=false;
    }
}

void solve()
{
    cin>>l>>r;
    clear();
    for(int i=r;i>=1;i--)
    {
        if(vis[i]) continue;
        int k=log2(i)+1;
        int a=(1<<k)-1-i;
        ans[i]=a,ans[a]=i;
        vis[i]=vis[a]=true;
    }
    LL total=((LL)l+r)*((LL)r-l+1);
    cout<<total<<endl;
    for(int i=l;i<=r;i++)
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