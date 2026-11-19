#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int n,q;
unordered_map<int,LL>f;
unordered_map<int,int>g;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        LL a;
        int u,v;
        cin>>a>>u>>v;
        f[u]=a;
        g[u]=v;
    }
    cin>>q;
    while(q--)
    {
        int u;
        cin>>u;
        cout<<f[u]<<' '<<g[u]<<endl;
    }
    return 0;
}