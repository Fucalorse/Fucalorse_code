#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int op[MAX],qwq=0;

int main()
{
    int val;
    while(scanf("%d",&val)==1) op[++qwq]=val;
    for(int i=1;i<=qwq;i++)
        printf("%d ",op[i]);
    return 0;
}