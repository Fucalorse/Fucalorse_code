#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int fs[MAX],ft[MAX];
string s,t;

void solve()
{
    cin>>n>>s>>t;
    s=' '+s,t=' '+t;

    int cs=0,ct=0;
    for(int i=1;i<=n;i++)
    {
        fs[i]=fs[i-1];
        ft[i]=ft[i-1];

        if(s[i]=='(') fs[i]++;
        else fs[i]--;

        if(t[i]=='(') ft[i]++;
        else ft[i]--;

        if(i<n&&s[i]=='('&&s[i+1]==')') ++cs;
        if(i<n&&t[i]=='('&&t[i+1]==')') ++ct;
    }

    if(cs!=ct)
    {
        cout<<"NO"<<endl;
        return;
    }

    auto get=[&](const string &s,int *a)
    {
        int cnt=INF;
        for(int i=1;i<=n;i++)
            if(s[i]==')'&&s[i+1]=='(') cnt=min(cnt,a[i]);
        return cnt;
    };

    if(get(s,fs)!=get(t,ft)) cout<<"NO"<<endl;
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