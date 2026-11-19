#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,LEN=26,MOD=998244353,INF=2e9;

string s;
char ans[MAX];

void solve()
{
    cin>>s;s=' '+s;

    int n=s.size()-1;
    vector<bool>del(n+1,false);

    for(int i=1;i<=n;i++)
        if(s[i]=='0')
        {
            del[i]=true;
            break;
        }

    for(int i=1;i<=n;i++)
        if(s[i]=='1')
        {
            del[i]=true;
            break;
        }

    for(int i=1;i<=n;i++)
    {
        if(del[i]) continue;
        cout<<s[i];
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