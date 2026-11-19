#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

struct qwq
{
    char w[15];
    double pa,pb,pc,sum;
}op[MAX];

int n;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf(" %s%lf%lf%lf",op[i].w,&op[i].pa,&op[i].pb,&op[i].pc);
        op[i].sum=op[i].pa+op[i].pb+op[i].pc;
    }
    for(int i=1;i<=n;i++)
        if(op[i].sum>=180) printf("%s -- pass exam\n",op[i].w);
    for(int i=1;i<=n;i++)
        if(op[i].sum<180) printf("%s -- not pass exam\n",op[i].w);
    for(int i=1;i<=n;i++)
        if(op[i].pa==100&&op[i].pb==100&&op[i].pc==100)
            printf("%s -- 3 x 100.0\n",op[i].w);
    return 0;
}