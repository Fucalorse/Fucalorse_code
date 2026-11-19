#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int max(int a,int b) { return a>b?a:b; }

int qwq=0;
char s[MAX],op[MAX];

int main()
{
    scanf("%[^\n]%*c",s+1);
    int len=strlen(s+1),ans=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='(') op[++qwq]=s[i];
        else if(s[i]==')') ans=max(ans,qwq),--qwq;
    }
    printf("%d",ans);
    return 0;
}