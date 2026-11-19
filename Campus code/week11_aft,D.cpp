#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 1e9
#define LL long long

struct tree
{
    int val,cnt;
}op[MAX];
typedef struct tree ovo;
int qwq=0;

void swap(ovo *a,ovo *b)
{
    ovo p=*a;
    *a=*b;
    *b=p;
}

void up()
{
    int i=qwq,j=qwq>>1;
    while(j>=1)
    {
        if(op[i].val<op[j].val) swap(op+i,op+j);
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
        if(j+1<=qwq&&op[j+1].val<op[j].val) j++;
        if(op[j].val<op[i].val) swap(op+i,op+j);
        else break;
        i=j;
        j<<=1;
    }
}

void push(ovo n)
{
    op[++qwq]=n;
    up();
}

void pop()
{
    op[1]=op[qwq--];
    down();
}

ovo top() { return op[1]; }

int size() { return qwq; }

int t,n;
int num[MAX];

void solve()
{
    scanf("%d",&n);
    qwq=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",num+i);
        ovo now={num[i],1};
        push(now);
    }
    int cnt=0;
    while(size()>1)
    {
        ovo a=top();pop();
        ovo b=top();pop();
        cnt+=a.cnt+b.cnt;
        ovo now={a.val+b.val,a.cnt+b.cnt};
        push(now);
    }
    printf("%.3lf\n",(double)cnt/n);
}

int main()
{
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}