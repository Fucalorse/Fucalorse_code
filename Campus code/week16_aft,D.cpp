#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

struct number
{
    int val,pos;
}op[MAX];
typedef struct number qwq;

int cmp(const void *a,const void *b)
{
    const qwq x=*(const qwq *)a;
    const qwq y=*(const qwq *)b;
    return x.val-y.val;
}

int n;
int a[MAX],to[MAX];
bool vis[MAX];

void clear()
{
    for(int i=1;i<=n;i++)
    {
        to[i]=0;
        vis[i]=false;
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        clear();

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&op[i].val);
            op[i].pos=i;
        }

        qsort(op+1,n,sizeof(qwq),cmp);
        for(int i=1;i<=n;i++)
            to[op[i].pos]=i;

        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;

            int len=0,cur=i;
            while(!vis[cur])
            {
                vis[cur]=true;
                cur=to[cur];
                ++len;
                // printf("%d ",cur);
            }
            ans+=len-1;
        }
        // printf("\n");

        printf("%d\n",ans);
    }
    return 0;
}