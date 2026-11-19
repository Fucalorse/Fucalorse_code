#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n,k;
int a[MAX],p[MAX];

int cal_l(int pos,int col)
{
    int ans=0;

    for(int l=1,r=1;l<pos;l=r)
    {
        while(r<pos&&a[l]==a[r]) r++;
        if(a[l]==col) ++ans;
    }

    return ans;
}

int cal_r(int pos,int col)
{
    int ans=0;

    for(int l=pos+1,r=pos+1;l<=n;l=r)
    {
        while(r<=n&&a[l]==a[r]) r++;
        if(a[l]==col) ++ans;
    }

    return ans;
}

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=k;i++)
        cin>>p[i];

    int pos=p[1];
    int cntl=cal_l(pos,a[pos]^1),cntr=cal_r(pos,a[pos]^1);
    int ans=min(cntl,cntr)<<1,rest=max(cntl,cntr)-min(cntl,cntr);
    ans+=rest<<1;

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