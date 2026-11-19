#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,INF=2e9,MOD=1e9+7;

string n;

void solve()
{
    cin>>n;

    int cnt=0;
    for(auto &cur:n)
        cnt+=cur=='9';

    string now;
    if(cnt==(int)n.size())
    {
        for(int i=1;i<=cnt;i++)
            now.push_back('9');
    }
    else
    {
        int sz=(int)n.size();
        for(int i=1;i<=sz-1;i++)
            now.push_back('9');
    }

    if(n>now) cout<<n<<endl;
    else cout<<now<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}