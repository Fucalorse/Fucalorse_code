#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
const int MAX=1e6+90;

int n,a,b;
ULL f[MAX],g[MAX];

int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        g[i]=i;
        f[i]=f[i-1]+g[i];
    }
    ULL total=0;
    for(int i=1;i<=n;i++)
        total+=f[i];
    for(int i=n-1;i>=1;i-=2)
        total+=f[i];
    int min1=min(b,a-b+1);
    for(int i=1;i<=min1;i++)
        total-=g[i];
    for(int i=min1+1;i<=a;i++)
    {
        if(i<=b||i<=a-b+1) total-=(ULL)min1;
        else total-=(ULL)a-i+1;
    }
    int m=min(n-a,a);
    for(int i=1;i<=m;i++)
    {
        if(i<=min1) total-=g[i];
        else
        {
            if(i<=b||i<=a-b+1) total-=(ULL)min1;
            else total-=(ULL)a-i+1;           
        }
    }
    cout<<total<<'\n';
    return 0;
}