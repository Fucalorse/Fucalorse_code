#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,mod=1e8-3;

struct qwq
{
    int val,id;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n;
int op[MAX];
vector<qwq>a,b;

int merge(int l,int r)
{
    int mid=(l+r)>>1;
    int i=l,j=mid+1,ans=0,a[n+1],qwq=0;
    while(i<=mid&&j<=r)
    {
        if(op[i]>op[j])
        {
            ans=(ans+mid-i+1)%mod;
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

int dfs(int l,int r)
{
    if(l>=r) return 0;
    int mid=(l+r)>>1;
    return (dfs(l,mid)+dfs(mid+1,r)+merge(l,r))%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    a.resize(n),b.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].val;
        a[i].id=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i].val;
        b[i].id=i+1;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        op[a[i].id]=b[i].id;
    cout<<dfs(1,n)<<'\n';
    return 0;
}