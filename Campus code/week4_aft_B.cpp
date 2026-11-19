#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int a[MAX],b[MAX],lena=0,lenb=0;

int main()
{
    int val;
    while(scanf("%d",&val)==1)
    {
        if(!val) break;
        if(val<0) b[++lenb]=val;
        else a[++lena]=val;
    }
    for(int i=1;i<=lena;i++)
        printf("%d ",a[i]);
    for(int i=1;i<=lenb;i++)
        printf("%d ",b[i]);
    return 0;
}