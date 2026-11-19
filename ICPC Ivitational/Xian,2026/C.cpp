#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int L[2][MAX],R[2][MAX],a[MAX];
string s;

void solve()
{
    cin>>n>>s;s=' '+s;

    int st,ed;
    for(st=1;st<=n;st++)
        if(s[st]=='(') break;
    for(ed=n;ed>=1;ed--)
        if(s[ed]==')') break;

    if(st>ed)
    {
        cout<<0<<endl;
        return;
    }

    for(int i=1,pre0=-INF,pre1=-INF;i<=n;i++)
    {
        if(s[i]=='(')
        {
            pre1=i;
            a[i]=1;
        }
        else
        {
            pre0=i;
            a[i]=0;
        }

        L[0][i]=pre0;
        L[1][i]=pre1;
    }

    for(int i=n,suf0=INF,suf1=INF;i>=1;i--)
    {
        if(s[i]=='(') suf1=i;
        else suf0=i;

        R[0][i]=suf0;
        R[1][i]=suf1;
    }

    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
    for(int len=1;len<=n;len++)
        for(int l=1;l<=n-len+1;l++)
        {
            int r=l+len-1;
            dp[l][r]=max(dp[l][r-1],dp[l+1][r]);
            if(a[l]==a[r])
            {
                int nl=R[a[l]^1][l],nr=L[a[r]^1][r];
                if(nl<nr) dp[l][r]=max(dp[l][r],4+dp[nl+1][nr-1]); 
            }
        }

    cout<<2+dp[st+1][ed-1]<<endl;
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