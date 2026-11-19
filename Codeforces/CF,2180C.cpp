#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=30;

int t,k;
LL n;

void solve()
{
    cin>>n>>k;
    if(k&1)
    {
        for(int i=1;i<=k;i++)
            cout<<n<<' ';
        cout<<endl;
    }
    else
    {
        vector<LL>ans(k+3,0);
        int p=0;
        for(int i=LEN;i>=0;i--)
        {
            if((n>>i)&1)
            {
                for(int j=1;j<=k;j++)
                {
                    if(j==min(p+1,k)) continue;
                    ans[j]|=1<<i;
                }
                if(p<=k) ++p;
            }
            else
            {
                for(int j=1;j<=p/2*2;j++)
                    ans[j]|=1<<i;
            }
        }
        for(int i=1;i<=k;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
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