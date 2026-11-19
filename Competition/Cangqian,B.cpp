#include <bits/stdc++.h>
using namespace std;

const int MAX=8090,inf=1e9;

int t,n;
vector<vector<int>>f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        f.assign(n+5,vector<int>(n+5,-inf));
        f[0][0]=0;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            char c;
            cin>>c;
            if(c=='B')
            {
                cnt++;
                for(int j=0;j<n;j++)
                    f[i][j]=max({f[i][j],f[i-1][j],f[i-1][j+1]+1});
            }
            else
            {
                int a,b;
                cin>>a>>b;
                for(int j=0;j<=n;j++)
                {
                    f[i][j]=max(f[i][j],min(cnt,f[i-1][j]+a));
                    f[i][j]=max(f[i][j],f[i-1][max(0,j-b)]);
                }
            }
        }
        int maxn=0;
        for(int i=0;i<=n;i++)
            maxn=max(maxn,f[n][i]);
        cout<<cnt+maxn<<'\n';
    }
    return 0;
}