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
    while(scanf("%d",&val)!=EOF) op[++qwq]=val;
    for(int i=qwq;i>=1;i--)
        printf("%d ",op[i]);
    return 0;
}