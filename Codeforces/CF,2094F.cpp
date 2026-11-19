#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,m,k;

void solve()
{
    cin>>n>>m>>k;
    if(m%k==0)
    {
        // cout<<121<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i&1)
            {
                for(int j=1,num=1;j<=m;j++,num=num%k+1)
                    cout<<num<<' ';
            }
            else
            {
                for(int j=m,num=k;j>=1;j--,num=num%k+1)
                    cout<<num<<' ';
            }
            cout<<endl;
        }
    }
    else
    {
        int num=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cout<<num<<' ';
                num=num%k+1;
            }
            cout<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}