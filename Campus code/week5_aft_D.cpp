#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,w;
int f[MAX];

int Max(int a,int b) { return a>b?a:b; }

int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        int a,val;
        scanf("%d%d",&a,&val);
        for(int k=w;k>=a;k--)
            f[k]=Max(f[k],f[k-a]+val);
    }
    printf("%d\n",f[w]);
    return 0;
}