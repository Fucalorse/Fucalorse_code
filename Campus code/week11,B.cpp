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

int top() { return op[1]; }

void pop()
{
    op[1]=op[qwq--];
    down();
}

int size() { return qwq; }

int t,n;
int a[MAX];

void solve()
{
    scanf("%d",&n);
    qwq=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        push(a[i]);
    }
    int ans=0;
    while(size()>1)
    {
        int a=top();pop();
        int b=top();pop();
        ans+=a+b;
        push(a+b);
    }
    printf("%d\n",ans);
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}