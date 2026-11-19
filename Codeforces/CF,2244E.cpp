#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct qwq
{
    int l,r,k;
}op[MAX];

int T,n,q;
string s;
int a[MAX],b[MAX];
int prea[MAX],preb[MAX];

void solve()
{
    cin>>n>>q>>s;s=' '+s;

    for(int i=1;i<=n;i++)
    {
        int p=s[i]-'0';

        if(i&1)
        {
            a[i]=p^1;
            b[i]=p^0;
        }
        else
        {
            a[i]=p^0;
            b[i]=p^1;
        }
    }

    for(int i=1;i<=n;i++)
    {
        prea[i]=prea[i-1];
        preb[i]=preb[i-1];

        if(i>=2&&a[i-1]==0&&a[i]==1) ++prea[i];

        if(i>=2&&b[i-1]==0&&b[i]==1) ++preb[i];
    }

    while(q--)
    {
        int l,r,k;
        cin>>l>>r>>k;

        int cnta=a[l]+prea[r]-prea[l];
        int cntb=b[l]+preb[r]-preb[l];

        int now=min(cnta,cntb);

        if(now>k) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}