#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1<<21;

int n;
int a[MAX];
string s;

int lowbit(int n) { return n&-n; }

void solve()
{
    cin>>n>>s;s=' '+s;

    int m=(1<<n)-1,sum=0;
    for(int i=1;i<=m;i++)
    {
        a[i]=s[i]-'0';
        if(a[i]) sum^=i;
    }
    a[sum]^=1;

    // for(int i=1;i<=m;i++)
    //     cout<<a[i]<<' ';
    // cout<<endl<<endl;
    
    vector<int>ans(m+1,0);
    for(int x=m;x>=1;x--)
    {
        if(!a[x]||(x&(x-1))==0) continue;
        int y=lowbit(x),z=x^y;

        a[x]^=1,a[y]^=1,a[z]^=1;
        ans[x]=y;
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}