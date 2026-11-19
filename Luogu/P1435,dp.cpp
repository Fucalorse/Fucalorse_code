#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

string a,b;
int f[MAX][MAX];

int main()
{
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());
    int len=a.size();
    a=" "+a;
    b=" "+b;
    for(int i=1;i<=len;i++)
        for(int j=1;j<=len;j++)
        {
            if(a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    cout<<len-f[len][len]<<'\n';
    return 0;
}