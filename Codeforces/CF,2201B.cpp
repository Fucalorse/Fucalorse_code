#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90;

int t,n,k;
int ans[MAX<<1];

void solve()
{
    cin>>n>>k;
    int l=n,r=2*n-1;
    if(k<l||k>r)
    {
        cout<<"NO"<<endl;
        return;
    }
    for(int i=1;i<=2*n;i+=2)
        ans[i]=ans[i+1]=(i+1)/2;
    for(int i=1,pos=2;i<=k-n;i++,pos+=2)
        swap(ans[pos],ans[pos+1]);
    cout<<"YES"<<endl;
    for(int i=1;i<=n*2;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}