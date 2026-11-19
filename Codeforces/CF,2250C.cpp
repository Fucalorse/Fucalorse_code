#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

int n;
int l[MAX],r[MAX],u[MAX],v[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>l[i]>>r[i]>>u[i]>>v[i];

    auto check=[&](int len)
    {
        int cnt=0;

        for(int i=1;i<=n;i++)
        {
            int j=cnt+1;
            int x=j,y=len-j+1;

            if((x<l[i]||x>r[i])&&(y<u[i]||y>v[i])) ++cnt;
        }

        return cnt>=len;
    };

    for(int len=n;len>=0;--len)
        if(check(len))
        {
            cout<<len<<endl;
            return;
        }
    
    cout<<0<<endl;
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