#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int pa,pb,lena,lenb,len;
int a[MAX],b[MAX];

int main()
{
    scanf("i=%d,len=%d,j=%d",&pa,&len,&pb);
    int val;
    while(scanf("%d",&val)==1)
    {
        if(val==-1) break;
        a[++lena]=val;
    }
    while(scanf("%d",&val)==1)
    {
        if(val==-1) break;
        b[++lenb]=val;
    }
    int l=pa-1,r=pa+len;
    for(int i=1;i<pb;i++)
        printf("%d ",b[i]);
    for(int i=1;i<=l;i++)
        printf("%d ",a[i]);
    for(int i=r;i<=lena;i++)
        printf("%d ",a[i]);
    for(int i=pb;i<=lenb-1;i++)
        printf("%d ",b[i]);
    printf("%d",b[lenb]);
    return 0;
}