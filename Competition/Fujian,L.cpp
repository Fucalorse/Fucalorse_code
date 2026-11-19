#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int t,n;
int a[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<2*a[1]<<' ';
    unordered_map<int,int>f;
    f[a[1]]++;
    int maxn=a[1],minn=a[1],max_cnt=1,num=a[1];
    for(int i=2;i<=n;i++)
    {
        ++f[a[i]];
        if(f[a[i]]>max_cnt)
        {
            max_cnt=f[a[i]];
            num=a[i];
        }
        else if(f[a[i]]==max_cnt&&a[i]>num) num=a[i];
        maxn=max(maxn,a[i]),minn=min(minn,a[i]);
        if(max_cnt>=i-1) cout<<max(maxn+minn,num*2)<<' ';
        else cout<<maxn+minn<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}