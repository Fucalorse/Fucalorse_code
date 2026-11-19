#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=150,LEN=60;

int n;
LL f[MAX];

void update(LL x)
{
    for(int i=0;i<=LEN;i++)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                break;
            }
            else x^=f[i];
        }
}

bool dis(LL x,const int &k)
{
    for(int i=0;i<=k;i++)
        if((x>>i)&1)
        {
            if(!f[i]) return false;
            x^=f[i];
        }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    LL sum=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        LL x;
        cin>>x;
        sum^=x;
        update(x);
    }
    for(int i=0;i<=LEN;i++)
        if(dis((1LL<<i)-1,i))
        {
            LL now=1LL<<(i+1);
            ans=max(ans,sum^(now-1));
        }
    cout<<ans<<'\n';
    return 0;
}