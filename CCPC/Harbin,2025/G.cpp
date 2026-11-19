#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1090,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n,m;
LL h[MAX][MAX];

void solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>h[i][j];

    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        vector<int>st;
        for(int j=1;j<=m;j++)
        {
            if(h[i][j]==0) continue;

            if(h[i][j]>0) st.push_back(j);
            else
            {
                while(st.size())
                {
                    int col=st.back();
                    if(h[i][col]<=llabs(h[i][j]))
                    {
                        h[i][j]+=h[i][col];
                        h[i][col]=0;
                        st.pop_back();
                    }
                    else
                    {
                        h[i][col]-=llabs(h[i][j]);
                        h[i][j]=0;
                        break;
                    }
                }
            }
        }

        for(int j=1;j<=m;j++)
        {
            if(h[i][j]>0)
            {
                if(i<n) h[i+1][j]+=h[i][j];
                else ans+=h[i][j];
            }
            else ans+=llabs(h[i][j]);
        }
    }

    cout<<ans<<endl;
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