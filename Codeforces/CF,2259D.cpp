#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];
char ans[MAX];

void solve()
{
    cin>>n;

    map<int,vector<int>>f;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]].push_back(i);
    }

    if(!f.count(0))
    {
        cout<<"YES"<<endl;
        cout<<string(n,'A')<<endl;
    }
    else if((int)f[0].size()==1) cout<<"NO"<<endl;
    else
    {
        vector<int>&op=f[0];
        int len=op.size();
        ans[op.front()]='A';
        for(int i=1;i<len;i++)
            ans[op[i]]='B';

        f.erase(0);

        for(auto &[val,vec]:f)
            for(auto &cur:vec)
                ans[cur]='C';

        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++)
            cout<<ans[i];
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