#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

LL op[MAX];
int qwq=0;

void swap(LL *a,LL *b)
{
    LL p=*a;
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
        if(j<=qwq&&op[j+1]<op[j]) j++;
        if(op[i]>op[j]) swap(op+i,op+j);
        else break;
        i=j;
        j<<=1;
    }
}

void push(LL n)
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

int n;
LL a[MAX];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",a+i);
        push(a[i]);
    }
    LL ans=0;
    while(qwq>=2)
    {
        LL a=top();pop();
        LL b=top();pop();
        ans+=a+b;
        push(a+b);
    }
    printf("%lld\n",ans);
    return 0;
}