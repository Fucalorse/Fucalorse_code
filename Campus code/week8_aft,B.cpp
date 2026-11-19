#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 1090

int n;
bool vis[MAX];
int num[MAX],op[MAX],ans[MAX],f[MAX][MAX];

bool dis()
{
    int qwq=0;
    for(int i=1,j=1;i<=n;i++)
    {
        ans[++qwq]=i;
        while(qwq&&ans[qwq]==op[j])
        {
            --qwq;
            j++;
        }
    }
    if(qwq) return false;
    else return true;
}

int dp(int push,int rest)
{
    if(push==n) return f[push][rest]=1;
    if(f[push][rest]) return f[push][rest];
    int cnt=0;
    if(push<n) cnt+=dp(push+1,rest+1);
    if(rest) cnt+=dp(push,rest-1);
    return f[push][rest]=cnt;
}

void dfs(int cnt)
{
    if(cnt>n)
    {
        // for(int i=1;i<=n;i++)
        //     printf("%d ",op[i]);
        // printf("\n");
        if(dis())
        {
            for(int i=1;i<=n;i++)
            {
                if(i>1) printf(" ");
                printf("%d",op[i]);
            }
            printf("\n");
        }
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            vis[i]=true;
            op[cnt]=i;
            dfs(cnt+1);
            vis[i]=false;
        }
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",dp(0,0));
    dfs(1);
    return 0;
}