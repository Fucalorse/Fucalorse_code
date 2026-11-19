#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n;
int f[MAX];

int main()
{
    while(scanf("%d",&n)==1)
    {
        if(!n) break;
        int st,ed;
        scanf("%d%d",&st,&ed);
        for(int i=1;i<=n;i++)
            scanf("%d",f+i);
        for(int i=ed;i>=st;i--)
        {
            printf("%d",f[i]);
            if(i!=st) printf(" ");
        }
        printf("\n");
    }
    return 0;
}