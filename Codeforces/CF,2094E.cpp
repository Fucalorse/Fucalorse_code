#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=32;

int t,n;
int c0[MAX],c1[MAX];
LL a[MAX];

void clear()
{
    for(int i=0;i<=LEN;i++)
        c0[i]=c1[i]=0;
}

void update(LL x)
{
    for(int k=LEN;k>=0;k--)
    {
        if((x>>k)&1) c1[k]++;
        else c0[k]++;
    }
}

LL get(LL x)
{
    LL ans=0;
    for(int k=LEN;k>=0;k--)
    {
        LL now=1LL<<k;
        if((x>>k)&1) ans+=now*c0[k];
        else ans+=now*c1[k];
    }
    return ans;
}

void solve()
{
    cin>>n;clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(a[i]);
    }

    LL maxn=0;
    for(int i=1;i<=n;i++)
        maxn=max(maxn,get(a[i]));
    cout<<maxn<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}