#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int n,m;
int q[MAX],h=1,t=0,size=0;

void push(int n)
{
    q[++t]=n;
    ++size;
}

void pop()
{
    ++h;
    --size;
}

int front() { return q[h]; }

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        push(i);
    int cnt=0;
    while(size>1)
    {
        int cur=front();pop();
        // printf("%d ",cur);
        if(++cnt==m) cnt=0;
        else push(cur);
    }
    printf("%d\n",front());
    return 0;
}