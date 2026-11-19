#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 2e9
#define LL long long

char s[MAX],t[MAX];
int op[MAX];

void create()
{
    int len=strlen(s);
    for(int i=1,j=0;i<len;i++)
    {
        while(j&&s[i]!=s[j]) j=op[j];
        if(s[i]==s[j]) j++;
        op[i+1]=j;
    }
}

void solve()
{
    scanf(" %s %s",t,s);
    create();
    int len=strlen(t),size=strlen(s),ans=1;
    for(int i=0,j=0;i<len;i++)
    {
        while(j&&t[i]!=s[j]) j=op[j],++ans;
        if(t[i]==s[j]) j++;
        else ++ans;
        if(j==size)
        {
            printf("%d %d\n",ans,i-size+2);
            return;
        }
    }
    printf("0\n");
}

int main()
{
    solve();
    return 0;
}