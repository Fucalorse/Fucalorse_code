#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 15

int n;
int num[MAX],cnt[MAX],op[MAX];

void dfs(int pos,int rest)
{
    if(rest<0) return;
    // printf("21\n");
    if(pos>10)
    {
        if(rest) return;
        // printf("%d\n",++n);
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=10;i++)
            cnt[op[i]]++;
        bool f=true;
        for(int i=1;i<=10;i++)
            if(num[i]<=9&&cnt[num[i]]!=op[i])
            {
                f=false;
                break;
            }
        if(f)
        {
            for(int i=1;i<=10;i++)
            {
                if(i!=1) printf(" ");
                printf("%d",op[i]);
            }
            exit(0);
        }
        return;
    }
    if(num[pos]<=9&&num[pos]>=0)
    {
        for(int i=0;i<=9;i++)
        {
            op[pos]=i;
            dfs(pos+1,rest-i);
        }
    }
    else
    {
        op[pos]=0;
        dfs(pos+1,rest);
    }
}

int main()
{
    for(int i=1;i<=10;i++)
        scanf("%d",num+i);
    dfs(1,10);
    printf("No answer!");
    return 0;
}