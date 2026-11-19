#include <bits/stdc++.h>
using namespace std;

const int MAX=45,LEN=1e5+90,inf=0x3f3f3f3f;

int n,minn=inf;
int f[MAX][LEN],num[MAX][MAX];
char s[MAX];

int main()
{
    cin>>(s+1)>>n;
    memset(f,0x3f,sizeof f);
    memset(num,0x3f,sizeof num);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        num[i][i]=s[i]-'0';
        for(int j=i+1;j<=len;j++)
        {
            if(num[i][j-1]*10>n) break;
            num[i][j]=num[i][j-1]*10+s[j]-'0';
        }
    }
    f[0][0]=-1;
    for(int i=1;i<=len;i++)
        for(int j=i-1;j>=0;j--)
        {
            if(num[j+1][i]>n) break;
            for(int k=num[j+1][i];k<=n;k++)
                f[i][k]=min(f[i][k],f[j][k-num[j+1][i]]+1);
        }
    printf("%d\n",f[len][n]==inf?-1:f[len][n]);
    return 0;
}