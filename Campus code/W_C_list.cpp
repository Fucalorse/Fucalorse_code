#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct qwq
{
    int r;
    char w[50];
}op[100090];

int n,head,tail;

void update()
{
    char now[50];
    scanf(" %s",now);
    if(!head)
    {
        head=tail=1;
        strcpy(op[head].w,now);
        op[head].r=0;
    }
    else
    {
        for(int i=head;i;i=op[i].r)
            if(strcmp(op[i].w,now)==0) return;
        strcpy(op[tail+1].w,now);
        op[tail].r=tail+1;
        ++tail;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        update();
    for(int i=head;i;i=op[i].r)
        printf("%s ",op[i].w);
    return 0;
}