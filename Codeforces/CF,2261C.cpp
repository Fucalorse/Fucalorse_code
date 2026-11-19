#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
LL a[MAX];

void solve()
{
    cin>>n;

    LL sum=0;
    int odd=0,even=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]&1) ++odd;
        else ++even;
    }

    if(n==1)
    {
        cout<<"Moggity"<<endl;
        return;
    }

    if(sum%2==0) cout<<"Moggity"<<endl;
    else
    {
        if(even>=1&&n>2) cout<<"Moggity"<<endl;
        else if(odd>=2&&n>3) cout<<"Moggity"<<endl;
        else cout<<"Larpity"<<endl;
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