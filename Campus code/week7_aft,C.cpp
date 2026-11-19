#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int op[MAX],qwq=0;
bool f[MAX];
void oula()
{
    memset(f,true,sizeof(bool)*(n+10));
    for(int i=2;i<=n;i++)
    {
        if(f[i]) op[++qwq]=i;
        for(int j=1;j<=qwq&&op[j]*i<=n;j++)
        {
            f[op[j]*i]=false;
            if(i%op[j]==0) break;
        }
    }
}

int main()
{
    scanf("%d",&n);
    if(n==1)
    {
        printf("YES");
        return 0;
    }
    oula();
    // for(int i=1;i<=qwq;i++)
    //     printf("%d ",op[i]);
    int cnt=0;
    for(int i=1;i<=qwq;i++)
        if(n%op[i]==0&&op[i]!=2&&op[i]!=5&&op[i]!=3) ++cnt;
    if(cnt) printf("NO");
    else printf("YES");
    return 0;
}