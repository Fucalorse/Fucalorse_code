#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int t,n;
int a[MAX];

void solve()
{
    cin>>n;
    vector<int>odd,even;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]&1) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    int maxn=-inf,minn=inf,now=-inf;
    for(auto &i:odd)
    {
        maxn=max(maxn,i);
        minn=min(minn,i);
    }
    // cout<<maxn<<' '<<minn<<endl;
    for(auto &i:even)
    {
        if(i>=now||minn<i||maxn>now) now=max(now,i);
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    maxn=now=-inf,minn=inf;
    for(auto &i:even)
    {
        maxn=max(maxn,i);
        minn=min(minn,i);
    }
    // cout<<maxn<<' '<<minn<<endl;
    for(auto &i:odd)
    {
        if(i>=now||minn<i||maxn>now) now=max(now,i);
        else
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}