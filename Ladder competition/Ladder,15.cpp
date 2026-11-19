#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n,m;
char c;

int main()
{
    cin>>n>>c;
    m=(n-1)/2+1;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<c;
        cout<<endl;
    }
    return 0;
}