#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define mod 1<<17
#define p 0x45d9f3b

struct qwq
{
    int key,val;
    struct qwq *nxt;
};
struct qwq *num[mod];

int cal(int n)
{
    n=((n>>16)^n)*p;
    n=((n>>16)^n)*p;
    n=(n>>16)^n;
    return n&((mod)-1);
}

void clear() { memset(num,0,sizeof num); }

void update(int n)
{
    int now=cal(n);
    struct qwq *cur=num[now];
    while(cur)
    {
        if(cur->key==n) cur->val++;
        cur=cur->nxt;
    }
    struct qwq *aft=(struct qwq*)malloc(sizeof(struct qwq));
    aft->nxt=num[now];
    num[now]=aft;
    aft->key=n;
    aft->val=1;
}

int find(int n)
{
    int now=cal(n);
    struct qwq *cur=num[now];
    while(cur)
    {
        if(cur->key==n) return cur->val;
        cur=cur->nxt;
    }
    return 0;
}

int n;
int rest[MAX],ans[MAX];

int main()
{
    clear();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        update(k);
    }
    scanf("%d",&n);
    int qwq=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        int now=find(k);
        if(now)
        {
            if(qwq&&rest[qwq]==k) continue;
            rest[++qwq]=k;
        }
    }
    scanf("%d",&n);
    clear();
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        update(k);
    }
    for(int i=1;i<=qwq;i++)
        if(find(rest[i])) printf("%d ",rest[i]);
    return 0;
}