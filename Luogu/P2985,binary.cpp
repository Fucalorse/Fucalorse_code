#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=5e4+90;

int n,m,ed;
int ans[MAX];
LL op[MAX];

bool dis(const LL &mid)
{
    LL total=0;
    for(int i=1,j=1;i<=m;i++)
    {
        while(j<=n&&total<mid)
        {
            total+=op[j];
            ans[j]=i;
            j++;
        }
        ed=j-1;
        if(total<mid) return false;
        total>>=1;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    LL l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        r+=op[i];
    }
    while(l<=r)
    {
        LL mid=(l+r)>>1;
        if(dis(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<'\n';
    dis(r);
    for(int i=1;i<=ed;i++)
        cout<<ans[i]<<'\n';
    for(int i=ed+1;i<=n;i++)
        cout<<m<<'\n';
    return 0;
}