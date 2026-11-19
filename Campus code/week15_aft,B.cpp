#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int op[MAX],qwq,size;

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
        if(op[i]>op[j]) swap(op+i,op+j);
        else break;
        i=j;
        j>>=1;
    }
}

void down(int st)
{
    int i=st,j=st<<1;
    while(j<=qwq)
    {
        if(j+1<=qwq&&op[j+1]>op[j]) j++;
        if(op[i]<op[j]) swap(op+i,op+j);
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
    swap(op+1,op+qwq);
    --qwq;
    down(1);
}

int top() { return op[1]; }

void initial(int n,int *a)
{
    qwq=n,size=n;
    for(int i=1;i<=n;i++)
        op[i]=a[i];
    for(int i=n>>1;i>=1;i--)
        down(i);
}

void print()
{
    for(int i=1;i<=size;i++)
    {
        if(i>1) printf(" ");
        printf("%d",op[i]);
    }
    printf("\n");
}

int n;
int a[MAX];

int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",a+i);
        initial(n,a);
        for(int i=1;i<=n;i++)
        {
            print();
            pop();
        }
    }
    return 0;
}