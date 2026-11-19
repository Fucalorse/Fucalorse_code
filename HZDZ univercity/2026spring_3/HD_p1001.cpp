#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=2e5+90;

int t,n,m;
LL a[MAX],b[MAX];

bool dis(const LL &mid)
{
    LL ans=0;
    bool f=false;
    for(int i=n,j=n+1;i>=1&&j>=1;)
    {
        if(mid>=a[i]&&!f) ans+=mid*b[j--],f=true;
        else ans+=a[i--]*b[j--];
        if(ans>=m) return true;
    }
    if(!f) ans+=mid*b[1];
    return ans>=m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n+1;i++)
            cin>>b[i];
        sort(a+1,a+n+1),sort(b+1,b+n+2);
        LL l=0,r=1e9;
        while(l<=r)
        {
            LL mid=(l+r)>>1;
            if(dis(mid)) r=mid-1;
            else l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}