#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n,m;
int p[MAX],a[MAX];

void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++)
        cin>>p[i];

    cin>>m;
    vector<int>ans;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        ans.push_back(a[i]);
    }

    sort(ans.begin(),ans.end());

    cout<<(int)ans.size()-1<<' ';
    for(size_t i=1;i<ans.size();i++)
        cout<<ans[i]<<' ';
    cout<<endl;
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