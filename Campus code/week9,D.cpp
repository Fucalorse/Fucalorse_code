#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char pre[MAX],aft[MAX];
int f[40],t;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        scanf(" %s %s",pre+1,aft+1);
        int len=strlen(pre+1);
        for(int i=1;i<=len;i++)
            f[aft[i]-'A']=i;
        int cnt=0;
        for(int i=1;i<len;i++)
        {
            int a=f[pre[i]-'A'],b=f[pre[i+1]-'A'];
            if(a==b+1) ++cnt;
        }
        printf("%d\n",1<<cnt);
    }
    return 0;
}