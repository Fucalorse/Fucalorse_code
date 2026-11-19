#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int n,m,k;
int a[MAX],f[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>a[i-1]) f[i]=f[i-1]+a[i]-a[i-1];
        else f[i]=f[i-1];
    }
    cin>>k;
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        cout<<f[r]-f[l]+k<<endl;
    }
    return 0;
}