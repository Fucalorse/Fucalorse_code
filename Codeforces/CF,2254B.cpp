#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=1e7,MOD=998244353,INF=2e9;

struct qwq
{
    char c;
    int l,r;
};

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    vector<qwq>op;
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&s[l]==s[r]) ++r;
        op.push_back({s[l],l,r-1});
    }

    int len=op.size(),ans=op.size();
    for(int i=1;i<len-1;i++)
    {
        if(op[i].l!=op[i].r) continue;

        if(op[i-1].c==op[i+1].c) ans=min(ans,len-2);
        else ans=min(ans,len-1);
    }

    cout<<ans<<endl;
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