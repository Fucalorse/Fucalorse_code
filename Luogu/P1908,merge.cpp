#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=5e5+90;

int n;
int op[MAX];

LL merge(int l,int r)
{
    int mid=(l+r)>>1;
    int i=l,j=mid+1,a[n+1],qwq=0;
    LL ans=0;
    while(i<=mid&&j<=r)
    {
        if(op[i]>op[j])
        {
            ans+=mid-i+1;
            a[qwq++]=op[j++];
        }
        else a[qwq++]=op[i++];
    }
    while(i<=mid) a[qwq++]=op[i++];
    while(j<=r) a[qwq++]=op[j++];
    for(int p=l;p<=r;p++)
        op[p]=a[p-l];
    return ans;
}

LL dfs(int l,int r)
{
    if(l>=r) return 0;
    int mid=(l+r)>>1;
    return dfs(l,mid)+dfs(mid+1,r)+merge(l,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>op[i];
    cout<<dfs(1,n)<<'\n';
    return 0;
}