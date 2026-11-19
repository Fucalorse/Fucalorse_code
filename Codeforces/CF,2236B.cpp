#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n,k;
string s;

void solve()
{
    cin>>n>>k>>s;s=' '+s;

    for(int i=1;i<=k;i++)
    {
        int cnt=0;

        for(int j=i;j<=n;j+=k)
            if(s[j]=='1') ++cnt;
        
        if(cnt&1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}