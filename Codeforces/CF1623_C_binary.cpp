#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

int t,n;
int op[MAX],f[MAX];

bool dis(const int &mid)
{
    memset(f,0,sizeof(int)*(n+10));
    for(int i=n;i>=3;i--)
    {
        if(op[i]+f[i]<mid) return false;
        int a=min((op[i]+f[i]-mid)/3,op[i]/3);
        f[i-1]+=a,f[i-2]+=a<<1;
        f[i]-=a*3;
    }
    for(int i=1;i<=2;i++)
        if(op[i]+f[i]<mid) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=0,r=0;
        for(int i=1;i<=n;i++)
        {
            cin>>op[i];
            if(op[i]>r) r=op[i];
        }
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