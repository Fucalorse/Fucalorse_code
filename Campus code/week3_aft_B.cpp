#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq,val;
int a[MAX],lena=0;
int b[MAX],lenb=0;

int main()
{
    scanf("%d",&qwq);
    for(int i=1;i<=qwq;i++)
    {
        scanf("%d",&val);
        if(i%2==1) a[++lena]=val;
        else b[++lenb]=val;
    }
    for(int i=1;i<=lena;i++)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=1;i<=lenb;i++)
        printf("%d ",b[i]);
    return 0;
}