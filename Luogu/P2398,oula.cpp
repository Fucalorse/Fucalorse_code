#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;

int n;
int phi[MAX];
LL f[MAX];
vector<int>op;

void oula()
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!phi[i])
        {
            phi[i]=i-1;
            op.push_back(i);
        }
        for(auto &j:op)
        {
            if((LL)i*j>n) break;
            if(i%j==0)
            {
                phi[i*j]=phi[i]*j;
                break;
            }
            else phi[i*j]=phi[i]*(j-1);
        }
    }
    for(int i=1;i<=n;i++)
        f[i]=f[i-1]+phi[i];
}

int main()
{
    cin>>n;
    oula();
    LL ans=0;
    for(int i=1;i<=n;i++)
        ans+=(LL)i*(f[n/i]*2-1);
    cout<<ans<<'\n';
    return 0;
}