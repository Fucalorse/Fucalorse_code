#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int f[MAX],qwq=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        bool g=true;
        scanf("%d",&k);
        for(int j=1;j<=qwq;j++)
            if(f[j]==k)
            {
                g=false;
                break;
            }
        if(g) f[++qwq]=k;
    }
    for(int i=1;i<=qwq;i++)
        printf("%d ",f[i]);
    return 0;
}