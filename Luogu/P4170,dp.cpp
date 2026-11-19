#include <bits/stdc++.h>
using namespace std;

const int MAX=60;

char s[MAX];
int f[MAX][MAX];

int main()
{
    cin>>(s+1);
    int n=strlen(s+1);
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)
        f[i][i]=1;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(s[i]==s[j]) f[i][j]=f[i][j-1];
            else
            {
                for(int k=i;k<j;k++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]);
            }
        }
    cout<<f[1][n]<<'\n';
    return 0;
}