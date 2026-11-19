#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=1e9;

int n,q;
int pre[MAX];
string s;

void solve()
{
    cin>>n>>q>>s;s=' '+s;

    for(int i=2;i<=n;i++)
        pre[i]=pre[i-1]+(s[i]==s[i-1]);

    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;

        int cnt=pre[r]-pre[l];
        int minn=(cnt+1)/2;
        if(minn<=k) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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