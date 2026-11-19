#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

int n;

bool check(int u,int v,int d)
{
    cout<<'?'<<' '<<u<<' '<<v<<' '<<d<<endl<<flush;

    int ans;
    cin>>ans;

    if(ans==-1) exit(0);

    return ans==1;
}

void solve()
{
    cin>>n;

    int d=0,pos;
    for(int i=2;i<=n;i++)
    {
        while(check(1,i,d+1))
        {
            ++d;
            pos=i;
        }
    }

    int to=1;

    for(int i=1;i<=n;i++)
    {
        while(check(pos,i,d+1))
        {
            ++d;
            to=i;
        }
    }

    cout<<'!'<<' '<<pos<<' '<<to<<' '<<d<<endl<<flush;
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