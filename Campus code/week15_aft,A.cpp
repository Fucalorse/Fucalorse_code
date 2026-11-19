#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int op[MAX],size;

void add(int n,int k)
{
    while(n<=size)
    {
        op[n]+=k;
        n+=n&-n;
    }
}

int query(int n)
{
    int ans=0;
    while(n)
    {
        ans+=op[n];
        n-=n&-n;
    }
    return ans;
}

void initial()
{
    size=26;
    for(int i=1;i<=26;i++)
        op[i]=0;
}

struct peach
{
    int cnt,id;
}ans[MAX];
typedef struct peach qwq;

int cmp(const void *a,const void *b)
{
    const qwq x=*(const qwq *)a;
    const qwq y=*(const qwq *)b;
    if(x.cnt!=y.cnt) return x.cnt-y.cnt;
    else return x.id-y.id;
}

int n,m;
int a[MAX];
char s[150][100];

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=m;i++)
        {
            initial();
            scanf(" %s",s[i]+1);
            char *now=s[i];
            int len=strlen(now+1);
            for(int j=1;j<=len;j++)
                a[j]=now[j]-'A'+1;
            
            int cnt=0;
            for(int j=len;j>=1;j--)
            {
                cnt+=query(a[j]-1);
                add(a[j],1);
            }
            ans[i].cnt=cnt,ans[i].id=i;
        }

        qsort(ans+1,m,sizeof(qwq),cmp);

        for(int i=1;i<=m;i++)
            printf("%s\n",s[ans[i].id]+1);
    }
    return 0;
}