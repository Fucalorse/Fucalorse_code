#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000090

int f[MAX];

int main()
{
    int val;
    while(scanf("%d",&val)==1)
    {
        if(val==-1) break;
        f[val]++;
    }
    while(scanf("%d",&val)==1)
    {
        if(val==-1) break;
        if(f[val]==0)
        {
            printf("No");
            exit(0);
        }
    }
    printf("Yes");
    return 0;
}