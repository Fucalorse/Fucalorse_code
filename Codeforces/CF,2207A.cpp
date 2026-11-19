#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

int n;
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int base=0;
    for(int i=1;i<=n;i++)
        base+=(s[i]=='1');

    vector<pair<int,int>>op;
    for(int l=1,r=1;l<=n;l=r)
    {
        if(s[l]=='0')
        {
            r++;
            continue;
        }

        while(r<=n&&s[r]=='1') ++r;
        op.push_back({l,r-1});
    }

    // for(auto &[l,r]:op)
    //     cout<<l<<' '<<r<<endl;

    int sub=0,add=0,len=op.size();
    for(int i=0;i<len-1;i++)
        if(op[i].second+2==op[i+1].first) ++add;
    for(int l=0,r=0;l<len;l=r)
    {
        while(r+1<len&&op[r].second+2==op[r+1].first) ++r;
        int now=op[r].second-op[l].first+1;
        sub+=(now-1)/2-(r-l);
        r++;
    }

    cout<<base-sub<<' '<<base+add<<endl;
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