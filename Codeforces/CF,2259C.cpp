#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    int st,ed;
    for(st=1;st<=n;++st)
        if(a[st]==1) break;
    for(ed=n;ed>=1;--ed)
        if(a[ed]==1) break;

    if(st<=ed)
    {
        for(int i=1;i<st;i++)
            if(a[i]==-1)
            {
                a[i]=1;
                break;
            }
        
        for(int i=n;i>ed;i--)
            if(a[i]==-1)
            {
                a[i]=1;
                break;
            }

        for(int i=1;i<=n;i++)
            if(a[i]==-1) a[i]=0;
    }
    else
    {
        for(int i=1;i<=n;i++)
            if(a[i]==-1)
            {
                a[i]=1;
                break;
            }

        for(int i=n;i>=1;i--)
            if(a[i]==-1)
            {
                a[i]=1;
                break;
            }

        for(int i=1;i<=n;i++)
            if(a[i]==-1) a[i]=0;
    }

    for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
    cout<<endl;
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