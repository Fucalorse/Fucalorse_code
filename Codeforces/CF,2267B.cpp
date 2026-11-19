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

    map<int,int,greater<int>>cnt;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    while(1)
    {
        if(cnt.empty()) break;

        set<int>del;
        for(auto it=cnt.begin();it!=cnt.end();++it)
        {
            cout<<it->first<<' ';
            --it->second;
            if(it->second==0) del.insert(it->first);
        }

        for(auto &cur:del)
            cnt.erase(cur);
    }

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