#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=30,MOD=998244353,INF=2e9;

int n;
int a[MAX],f[LEN+3],b[MAX];

void clear()
{
    for(int i=0;i<=LEN;i++)
        f[i]=0;
}

void update(int x)
{
    for(int i=LEN;i>=0;i--)
        if((x>>i)&1)
        {
            if(!f[i])
            {
                f[i]=x;
                return;
            }

            x^=f[i];
        }
}

int get_max()
{
    int ans=0;
    for(int i=LEN;i>=0;i--)
        ans=max(ans,ans^f[i]);

    return ans;
}

void solve()
{
    cin>>n;clear();

    int S=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        S^=a[i];
    }

    for(int i=1;i<=n;i++)
    {
        b[i]=(~S)&a[i];
        update(b[i]);
    }

    cout<<S+2*get_max()<<endl;
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