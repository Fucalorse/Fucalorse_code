#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1000

struct square
{
    int row,col,val;
}a[MAX],b[MAX],c[MAX];
typedef struct square qwq;

int lena=0,lenb=0,lenc=0;

void update(int x,int y,int v)
{
    for(int i=1;i<=lenc;i++)
        if(c[i].row==x&&c[i].col==y)
        {
            c[i].val+=v;
            return;
        }
    qwq ans={x,y,v};
    c[++lenc]=ans;
}

int main()
{
    int row,col,val;
    while(scanf("%d,%d,%d",&row,&col,&val)==3)
    {
        if(row==-1&&col==-1&&val==-1) break;
        qwq ans={row,col,val};
        a[++lena]=ans;
    }
    while(scanf("%d,%d,%d",&row,&col,&val)==3)
    {
        if(row==-1&&col==-1&&val==-1) break;
        qwq ans={row,col,val};
        b[++lenb]=ans;
    }
    for(int i=1;i<=lena;i++)
        for(int j=1;j<=lenb;j++)
            if(a[i].col==b[j].row)
            {
                int x=a[i].col,y=b[j].row,now=a[i].val*b[j].val;
                update(x,y,now);
            }
    if(!lenc) printf("No non-zero number exists!\n");
    else
    {
        for(int i=1;i<=lenc;i++)
            printf("%d,%d,%d\n",c[i].row,c[i].col,c[i].val);
    }
    return 0;
}