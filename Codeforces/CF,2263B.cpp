#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,k;

void solve()
{
    cin>>n>>k;

    if(k<n||k>2*n-1)
    {
        cout<<-1<<endl;
        return;
    }

    int rest=k-n,num=0;
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    a[1][1]=++num;
    for(int i=2;i<=n;i++)
    {
        if(rest)
        {
            a[i][1]=++num;
            --rest;
        }
        else a[i][i]=++num;
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!a[i][j]) a[i][j]=++num;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}