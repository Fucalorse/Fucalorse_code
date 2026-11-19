#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,k;
int a[MAX];
string s;

void solve()
{
    cin>>n>>k>>s;s=' '+s;
    int m=n<<1;

    for(int i=1;i<=m;i++)
        a[i]=s[i]-'0';
    
    vector<int>op;
    for(int i=1;i<=m;i++)
    {
        int j=i%m+1;
        if(a[i]^a[j]&&a[i]==1) op.push_back(i);
    }

    // for(auto &cur:op)
    //     cout<<cur<<' ';
    // cout<<endl;

    for(auto &cur:op)
    {
        int nxt=cur%m+1;
        swap(a[cur],a[nxt]);
    }
    
    int r=0,b=0;
    for(int i=1;i<=m;i++)
    {
        if(i&1) r+=a[i];
        else b+=a[i]; 
    }

    cout<<b<<' '<<r<<endl;
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