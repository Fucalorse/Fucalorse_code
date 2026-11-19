#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

struct student
{
    char name[140];
    LL score;
}op[MAX];
typedef struct student qwq;

int cmp(const void *a,const void *b)
{
    const qwq x=*(const qwq *)a,y=*(const qwq *)b;
    
    if(x.score!=y.score) return y.score-x.score;
    else return strcmp(x.name,y.name);
}

int T,n,m;
LL num[MAX];

void solve()
{
    scanf("%d%d",&n,&m);

    LL sum=0;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",num+i);
        sum+=num[i];
    }

    for(int i=1;i<=n;i++)
    {
        scanf(" %s",op[i].name);
        LL total=0;

        for(int j=1;j<=m;j++)
        {
            LL now;
            scanf("%lld",&now);
            total+=now*num[j];
        }

        op[i].score=total;
    }

    qsort(op+1,n,sizeof(qwq),cmp);

    for(int i=1;i<=n;i++)
        printf("%s\n",op[i].name);
    printf("\n");
}

int main()
{
    T=1;
    while(T--) solve();
    return 0;
}