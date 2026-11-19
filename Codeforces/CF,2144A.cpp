#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n;
int a[MAX],f[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=(f[i-1]+a[i])%3;
    }

    auto check=[&](int l,int mid,int r)
    {
        if(l!=mid&&l!=r&&mid!=r) return true;
        if(l==mid&&mid==r) return true;
        return false;
    };

    for(int l=1;l<=n;l++)
        for(int r=l+1;r<n;r++)
        {
            int left=f[l],mid=(f[r]-f[l]+3)%3,right=(f[n]-f[r]+3)%3;

            if(check(left,mid,right))
            {
                cout<<l<<' '<<r<<endl;
                return;
            }
        }

    cout<<0<<' '<<0<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}