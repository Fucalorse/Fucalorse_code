#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int suf[MAX],nxt[MAX];
char s[MAX];

void solve()
{
    cin>>n>>(s+1);
    suf[n+1]=0,nxt[n+1]=n+1;
    for(int i=n;i>=1;i--)
    {
        suf[i]=suf[i+1]+(s[i]=='(');
        if(s[i]=='(') nxt[i]=i;
        else nxt[i]=nxt[i+1];
    }
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==')'&&nxt[i]<=n)
        {
            int len=nxt[i]-i;
            if(suf[nxt[i]+1]>=len) ans=max(ans,n-len*2);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}