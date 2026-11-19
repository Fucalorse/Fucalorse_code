#include <bits/stdc++.h>
using namespace std;

const int MAX=3e5+90,LEN=60;

int n;
int f[MAX][LEN+10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        f[i][a]=i+1;
    }
    int ans=0;
    for(int j=1;j<=LEN;j++)
        for(int i=1;i<=n;i++)
        {
            if(!f[i][j]) f[i][j]=f[f[i][j-1]][j-1];
            if(f[i][j]) ans=max(ans,j);
        }
    cout<<ans<<'\n';
    return 0;
}