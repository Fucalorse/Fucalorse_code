#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090;

int T,n,m;
int ans[MAX][MAX];

void solve()
{
    cin>>n>>m;

    if(2*n<m+1)
    {
        cout<<"NO"<<endl;
        return;
    }

    for(int col=1;col<=n;col++)
        for(int k=1;k<=m;k++)
        {
            int i=(2*(col-1)+k-1)%(2*n)+1;
            int j=i%(2*n)+1;
            ans[i][k]=ans[j][k]=col;
        }
    
    cout<<"YES"<<endl;
    for(int i=1;i<=2*n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}