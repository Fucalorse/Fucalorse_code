#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int op[MAX],qwq=0;

void swap(int *a,int *b)
{
    int p=*a;
    *a=*b;
    *b=p;
}

void up()
{
    int i=qwq,j=qwq>>1;
    while(j>=1)
    {
        if(op[i]<op[j]) swap(op+i,op+j);
        else break;
        i=j;
        j>>=1;
    }
}

void down()
{
    int i=1,j=2;
    while(j<=qwq)
    {
        if(op[j+1]<op[j]) j++;
        if(op[i]>op[j]) swap(op+i,op+j);
        else break;
        i=j;
        j<<=1;
    }
}

void push(int n)
{
    op[++qwq]=n;
    up();
}

int top() { return op[1]; }

void pop()
{
    op[1]=op[qwq--];
    down();
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        push(a);
    }
    for(int i=1;i<=k;i++)
    {
        if(i>1) printf(" ");
        printf("%d",top());
        pop();
    }
    return 0;
}