#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n,k;
int ans[MAX];

void solve()
{
    cin>>n>>k;

    if(k>n-2)
    {
        cout<<-1<<endl;
        return;
    }

    int pos=0;

    if(k%2==0)
    {
        for(int i=1;i<=k/2+1;i++)
            ans[++pos]=0;
        for(int i=1;i<=k/2+1;i++)
            ans[++pos]=1;
        
        for(int i=pos+1;i<=n;i++)
            ans[i]=ans[i-1]^1;
    }
    else
    {
        int now=k/2;
        for(int i=1;i<=now+1;i++)
            ans[++pos]=0;
        for(int i=1;i<=now+2;i++)
            ans[++pos]=1;

        for(int i=pos+1;i<=n;i++)
            ans[i]=ans[i-1]^1;
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i];
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