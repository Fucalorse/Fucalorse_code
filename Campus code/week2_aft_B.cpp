#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,minn=2e9;
int f[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",f+i);
        if(f[i]<minn) minn=f[i];
    }
    printf("%d",minn);
    return 0;
}