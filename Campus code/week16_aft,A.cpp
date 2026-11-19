#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

void swap(int *a,int *b)
{
    int p=*a;
    *a=*b;
    *b=p;
}

int a,b,c;

int main()
{
    scanf("%d%d%d",&a,&b,&c);

    if(a>b) swap(&a,&b);
    if(a>c) swap(&a,&c);
    if(b>c) swap(&b,&c);

    printf("%d %d %d\n",a,b,c);
    
    return 0;
}