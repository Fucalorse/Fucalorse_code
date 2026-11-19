#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
LL x,y;
char s[MAX];
LL p[MAX],a[MAX],b[MAX];

void solve()
{
    cin>>n>>x>>y>>(s+1);
    LL sum=0;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        sum+=p[i];
        cnt+=s[i]=='1';
    }
    if(sum>x+y)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(cnt==n||cnt==0)
    {
        if(cnt==n) swap(x,y);
        LL now=0;
        for(int i=1;i<=n;i++)
            now+=(p[i]>>1)+1;
        if(now>x||x<y+n) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        return;
    }
    else
    {
        LL suma=0,sumb=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') suma+=(p[i]>>1)+1;
            else sumb+=(p[i]>>1)+1;
        }
        if(x>=suma&&y>=sumb) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}