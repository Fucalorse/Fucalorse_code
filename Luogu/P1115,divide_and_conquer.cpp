#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,inf=2e9;

int n;
int f[MAX];

int dfs(int l,int r)
{
    if(l==r) return f[l];
    int mid=(l+r)>>1;
    int numl=-inf,numr=-inf;
    for(int i=mid,sum=0;i>=l;i--)
    {
        sum+=f[i];
        numl=max(numl,sum);
    }
    for(int i=mid+1,sum=0;i<=r;i++)
    {
        sum+=f[i];
        numr=max(numr,sum);
    }
    return max(max(dfs(l,mid),dfs(mid+1,r)),numl+numr);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    cout<<dfs(1,n)<<'\n';
    return 0;
}