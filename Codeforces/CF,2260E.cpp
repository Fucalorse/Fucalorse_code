#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n,q;
string s;

void solve()
{
    cin>>n>>q>>s;s=' '+s;

    vector<int>f(n+3,0),cnt0(n+3,0),cnt1(n+3,0);
    for(int i=2;i<=n;i++)
    {
        cnt0[i]=cnt0[i-1],cnt1[i]=cnt1[i-1],f[i]=f[i-1];

        if(s[i]==s[i-1])
        {
            if(s[i]=='0') cnt0[i]++;
            else cnt1[i]++;
        }
        else f[i]++;
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int c0=cnt0[r]-cnt0[l],c1=cnt1[r]-cnt1[l],edge=f[r]-f[l];
        if(s[r]==s[l])
        {
            if(s[l]=='0') ++c0;
            else ++c1;
        }
        else ++edge;

        int L=1,R=(c0*2+c1*2+edge)*2;
        while(L<=R)
        {
            int mid=(L+R)>>1;
            int con=edge;
            if(mid<c0) con+=2*(c0-mid);
            if(mid<c1) con+=2*(c1-mid);

            if(con<=mid*2) R=mid-1;
            else L=mid+1;
        }

        cout<<L*4-(r-l+1)<<endl;
    }
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