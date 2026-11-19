#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=200,inf=2e9;

struct qwq
{
    int val,cnt;
}op[MAX];

int T,n;
int a[MAX],sum[MAX];

void solve()
{
    cin>>n;

    map<int,int>num;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++num[a[i]];
    }

    int m=0;
    for(auto &[val,cnt]:num)
        op[++m]={val,cnt};

    if(m==1)
    {
        cout<<0<<endl;
        return;
    }

    for(int i=1;i<=m;i++)
        sum[i]=sum[i-1]+op[i].cnt;

    int ans=2e9;
    for(int i=1;i<=m;i++)
    {
        int l=sum[i-1],mid=op[i].cnt,r=sum[m]-sum[i];

        // cout<<l<<' '<<mid<<' '<<r<<endl;

        if(l>r) swap(l,r);
        if(l+mid>=r) ans=min(ans,r);
    }

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