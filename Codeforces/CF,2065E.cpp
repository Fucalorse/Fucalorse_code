#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n,m,k;
int ans[MAX];

void solve()
{
    cin>>n>>m>>k;

    int a=0,b=1;
    if(n<m) swap(n,m),swap(a,b);
    if(n-k>m||n-k<0) cout<<-1<<endl;
    else
    {
        int qwq=0;
        for(int i=1;i<=k;i++)
            ans[++qwq]=a;
        n-=k;
        for(int i=1;i<=min(n,m)*2;i++)
        {
            if(i&1) ans[++qwq]=b;
            else ans[++qwq]=a;
        }
        m-=min(n,m);
        for(int i=1;i<=m;i++)
            ans[++qwq]=b;
        
        for(int i=1;i<=qwq;i++)
            cout<<ans[i];
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}