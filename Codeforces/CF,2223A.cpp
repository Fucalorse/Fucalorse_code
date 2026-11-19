#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
string a,b;

void solve()
{
    cin>>n>>a>>b;
    a=' '+a,b=' '+b;

    int suma=0,sumb=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i])
        {
            if(a[i]=='(') ++suma,++sumb;
            else --suma,--sumb;
        }
        else
        {
            if(suma>sumb) ++sumb,--suma;
            else ++suma,--sumb;
        }

        if(suma<0||sumb<0)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    if(suma!=0||sumb!=0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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