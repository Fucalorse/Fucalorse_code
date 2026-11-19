#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=26,MOD=998244353;

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int L=2*n-1;
    vector<LL>cnt1(m+1,0),cnt2(m+1,0),cnt3(m+1,0),ans(m+1,0);
    ans[1]=n;

    for(int i=1;i<=n;i++)
    {
        int q=a[i]/L,r=a[i]%L;
        int x=2*(n-i),y=2*i-1;

        if(r>=x)
        {
            if(q+1<=m) cnt1[q+1]++;
        }
        else if(r<x&&r<y)
        {
            if(q+1<=m) cnt2[q]++;
        }
        else
        {
            if(q+1<=m) cnt3[q+1]++;
        }
    }

    for(int p=1;p<=m;p++)
    {
        if(cnt1[p])
        {
            for(int k=1+p;k<=m;k+=p)
                ans[k]+=cnt1[p];
        }
        if(cnt3[p])
        {
            for(int k=p;k<=m;k+=p)
                ans[k]+=cnt3[p];
        }
    }

    for(int q=0;q<=m;q++)
    {
        if(cnt2[q]==0) continue;

        int gap=2*q+1;
        for(int k=1+q;k<=m;k+=gap)
            ans[k]+=cnt2[q];
        for(int k=1+gap;k<=m;k+=gap)
            ans[k]+=cnt2[q];
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
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