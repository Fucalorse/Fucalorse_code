#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90;

int t,n,m;

void solve()
{
    cin>>n>>m;
    vector<vector<int>>a(n+3,vector<int>(m+3)),f(n+3,vector<int>(m+3,0));
    LL cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            cnt+=a[i][j];
            f[i][j]=f[i][j-1]+a[i][j];
        }
    LL c=cnt/2,d=(cnt+1)/2;
    int now=0,pos=1;
    cout<<c*d<<endl;
    for(int i=1;i<=n;i++)
    {
        while(pos<=m&&f[i][m]-f[i][pos-1]+now>cnt/2)
        {
            ++pos;
            cout<<'R';
        }
        now+=f[i][m]-f[i][pos-1];
        cout<<'D';
    }
    while(pos<=m)
    {
        cout<<'R';
        ++pos;
    }
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