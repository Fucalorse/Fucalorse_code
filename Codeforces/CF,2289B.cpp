#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,k;
int a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int ans=0,len=n-k+1;
    map<int,int>cnt;
    for(int l=1,r=1;l<=n;l++)
    {
        while(r<=n&&r-l+1<=len)
        {
            ++cnt[a[r]];
            r++;
        }

        if((int)cnt.size()==1) ++ans;
        --cnt[a[l]];
        if(cnt[a[l]]==0) cnt.erase(a[l]);

        if(r>n) break;
    }

    cout<<ans<<endl;
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