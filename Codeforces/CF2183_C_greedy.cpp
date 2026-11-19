#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

int t,n,m,k;

bool dis(const int &mid)
{
    int a=(mid-1)>>1,b=mid-1-a;
    if(k-a>=1&&k+b<=n) return a+b+max(a,b)-1<=m;
    else
    {
        int x=min(k-1,n-k),y=mid-1-x;
        return x+y+max(x,y)-1<=m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        int l=0,r=n;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(dis(mid)) l=mid+1;
            else r=mid-1;
        }
        cout<<r<<'\n';
    }
    return 0;
}