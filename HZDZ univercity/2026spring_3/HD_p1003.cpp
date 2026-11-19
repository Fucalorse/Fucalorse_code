#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=9;

int t,n;
LL f[12];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(f,0,sizeof f);
        LL maxn=0;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            LL val;
            cin>>x>>y>>val;
            if(x==2&&y==2) maxn=max(maxn,val);
            else
            {
                int a=x*y;
                for(int k=MAX;k>=a;k--)
                    f[k]=max(f[k],f[k-a]+val);
            }
        }
        LL ans=f[MAX];
        for(int i=0;i<=5;i++)
            ans=max(ans,f[i]+maxn);
        cout<<ans<<'\n';
    }
}