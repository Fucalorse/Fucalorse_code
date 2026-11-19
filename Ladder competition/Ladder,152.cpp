#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+90;

int n,m,k;
vector<vector<int>>op;
unordered_map<int,int>f;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    op.assign(n+5,vector<int>{});
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        op[i].assign(k+5,0);
        for(int j=1;j<=k;j++)
            cin>>op[i][j];
    }
    int now=1;
    while(m--)
    {
        int p,j;
        cin>>p>>j;
        if(p==0) now=op[now][j];
        else if(p==1)
        {
            f[j]=now;
            cout<<now<<endl;
        }
        else now=f[j];
    }
    cout<<now<<endl;
    return 0;
}