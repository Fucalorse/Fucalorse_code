#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n,k;
LL num[10];
string a,b,c;

void solve()
{
    cin>>n>>k>>a>>b;a=' '+a,b=' '+b;

    c=' ';
    for(int i=1;i<=n;i++)
    {
        int now=(a[i]-'0')^(b[i]-'0');

        if(now) c+='1';
        else c+='0';
    }

    auto cal=[&](const string &s)
    {
        LL c0=0;

        for(int i=1;i<=n;i++)
            if(s[i]=='0') ++c0;

        return c0*(n-c0);
    };

    num[1]=cal(a);
    if(k&1)
    {
        num[2]=cal(c);
        num[3]=cal(b);
    }
    else
    {
        num[2]=cal(b);
        num[3]=cal(c);
    }

    LL sum=num[1]+num[2]+num[3],cnt=(1LL<<k)+1;
    LL ans=cnt/3*sum,r=cnt%3;
    for(int i=1;i<=r;i++)
        ans+=num[i];

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}