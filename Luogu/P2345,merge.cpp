#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e4;

struct ovo
{
    LL v,x;
    bool operator<(const ovo &a)const { return v<a.v; }
}op[MAX];
int n;

LL merge(int l,int r)
{
    int mid=(l+r)>>1;
    LL suml=0,sumr=0,ans=0;
    for(int i=l;i<=mid;i++)
        suml+=op[i].x;
    for(int i=mid+1,h=l;i<=r;i++)
    {
        while(h<=mid&&op[i].x>op[h].x)
        {
            sumr+=op[h].x;
            suml-=op[h].x;
            h++;
        }
        ans+=op[i].v*(suml-op[i].x*(mid-h+1)+op[i].x*(h-l)-sumr);
    }
    int i=l,j=mid+1,qwq=0;
    ovo a[n+1];
    while(i<=mid&&j<=r)
    {
        if(op[i].x<op[j].x) a[qwq++]=op[i++];
        else a[qwq++]=op[j++];
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
        cin>>op[i].v>>op[i].x;
    sort(op+1,op+n+1);
    cout<<dfs(1,n)<<'\n';
    return 0;
}