#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    map<int,int>f;
    bool ok=true;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++f[a[i]];
        if(f[a[i]]>=2) ok=false;
    }

    if(!ok) cout<<-1<<endl;
    else
    {
        for(auto it=f.rbegin();it!=f.rend();++it)
            cout<<it->first<<' ';
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