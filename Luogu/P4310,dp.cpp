#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=30;

int n;
int num[MAX],f[MAX],op[40];

int update(const int &x)
{
    int maxn=0;
    for(int i=0;i<=LEN;i++)
        if((x>>i)&1) maxn=max(maxn,op[i]+1);
    for(int i=0;i<=LEN;i++)
        if((x>>i)&1) op[i]=max(op[i],maxn);
    return maxn;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>num[i];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i]=update(num[i]);
        ans=max(ans,f[i]);
    }
    cout<<ans<<'\n';
    return 0;
}