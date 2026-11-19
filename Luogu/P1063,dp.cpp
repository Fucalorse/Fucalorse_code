#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=220;

struct qwq
{
    LL l,r,val;
}f[MAX][MAX];

int n;
LL op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op[i];
        op[i+n]=op[i];
    }
    int len=n<<1;
    op[len+1]=op[1];
    for(int i=1;i<=len;i++)
        f[i][i]={op[i],op[i+1],0};
    for(int s=2;s<=len;s++)
        for(int i=1;i+s-1<=len;i++)
        {
            int j=i+s-1;
            for(int k=i;k<j;k++)
            {
                LL now=f[i][k].val+f[k+1][j].val+f[i][k].l*f[i][k].r*f[k+1][j].r;
                if(now>f[i][j].val)
                {
                    f[i][j].val=now;
                    f[i][j].l=f[i][k].l;
                    f[i][j].r=f[k+1][j].r;
                }
            }
        }
    LL ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,f[i][i+n-1].val);
    cout<<ans<<'\n';
    return 0;
}