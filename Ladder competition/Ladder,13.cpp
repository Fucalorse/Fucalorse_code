#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=100;

int n;
int f[MAX];

int main()
{
    cin>>n;
    int ans=1;
    f[1]=1;
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]*i;
        ans+=f[i];
    }
    cout<<ans<<endl;
    return 0;
}