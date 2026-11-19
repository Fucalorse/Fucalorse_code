#include <bits/stdc++.h>
using namespace std;

const int MAX=2090;

char a[MAX],b[MAX];
int f[MAX][MAX];

int main()
{
    cin>>(a+1)>>(b+1);
    int lena=strlen(a+1),lenb=strlen(b+1);
    for(int i=0;i<=lena;i++)
        f[i][0]=i;
    for(int i=0;i<=lenb;i++)
        f[0][i]=i;
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
        {
            int p=a[i]==b[j]?0:1;
            f[i][j]=min(min(f[i-1][j]+1,f[i][j-1]+1),f[i-1][j-1]+p);
        }
    cout<<f[lena][lenb]<<'\n';
    return 0;
}