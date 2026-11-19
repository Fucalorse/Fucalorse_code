#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const vector<string>base={"","1","11","101","0101"};

int n;

void solve()
{
    cin>>n;

    if(n<=4)
    {
        cout<<base[n]<<endl;
        return;
    }

    int len=(n+1)/3,r=(n+1)%3;
    vector<int>pos;
    if(len&1)
    {
        pos={len-2,2*len-2,2*len};
        if(r==2)
        {
            for(auto &cur:pos)
                ++cur;
        }
    }
    else
    {
        pos={len,2*len};
        if(r==2)
        {
            for(auto &cur:pos)
                ++cur;
        }
    }

    string ans;
    vector<bool>is_one(n+1,false);
    for(auto &cur:pos)
        is_one[cur]=true;

    for(int i=1;i<=n;i++)
    {
        if(is_one[i]) ans.push_back('1');
        else ans.push_back('0');
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