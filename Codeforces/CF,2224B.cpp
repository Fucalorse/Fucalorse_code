#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
LL a[MAX],mex[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    sort(a+1,a+n+1);

    int len=0;
    for(int i=1;i<=n;i++)
        if(a[i]==len) ++len;

    mex[1]=a[n]==0?1:0;
    for(int i=2,cnt=1;i<=n;i++,++cnt)
    {
        mex[i]=min(len,cnt);
        if(mex[i]==len-1&&a[n]==len-1) mex[i]=len;
    }

    // for(int i=1;i<=n;i++)
    //     cout<<mex[i]<<' ';
    // cout<<endl;

    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=a[n]+mex[i];

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}