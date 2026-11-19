#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,k;
LL a[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    LL ans=0;
    int l=k,r=n-k+1;
    vector<bool>del(n+1,false);
    while(l<r)
    {
        if(a[l]>a[r])
        {
            ans+=a[l];
            del[l]=true;
            ++l;
        }
        else
        {
            ans+=a[r];
            del[r]=true;
            --r;
        }
    }

    vector<LL>rest;
    if(l==r)
    {
        for(int i=1;i<=n;i++)
            if(!del[i]) rest.push_back(a[i]);
    }
    else
    {
        for(int i=1;i<=r;i++)
            rest.push_back(a[i]);
        for(int i=l;i<=n;i++)
            rest.push_back(a[i]);
    }

    int len=rest.size();
    for(int i=0;i<=(len-1)/2;i++)
    {
        int l=i,r=len-i-1;
        ans+=max(rest[l],rest[r]);
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