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

    cout<<"YES"<<endl;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int len=2*n;
            int col=((i-j+len)%len)/2+1;
            cout<<col<<' '; 
        }
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