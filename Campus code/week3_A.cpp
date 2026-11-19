#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define  MAX 100090

int n;
int op[MAX];

int main()
{
    scanf("%d",&n);
    int minn=2e9,pos;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",op+i);
        if(op[i]<minn) minn=op[i],pos=i;
    }
    printf("%d ",minn);
    for(int i=1;i<=n;i++)
    {
        if(pos==i) continue;
        printf("%d ",op[i]);
    }
    return 0;
}