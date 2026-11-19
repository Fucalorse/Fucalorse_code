#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

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
        if(j+1<=qwq&&op[j+1]<op[j]) j++;
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

void pop()
{
    op[1]=op[qwq--];
    down();
}

int top() { return op[1]; }

int size() { return qwq; }

int n;
int a[MAX];

int main()
{
    while(scanf("%d",&n)==1)
    {
        qwq=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            push(a[i]);
        }
        while(size())
        {
            printf("%d",top());
            if(size()!=1) printf(" ");
            pop();
        }
        printf("\n");
    }
    return 0;
}