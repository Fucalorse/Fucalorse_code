#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq=0,n;
char s[MAX],op[MAX],ans[MAX];

int main()
{
    scanf("%[^\n]%*c%d",s+1,&n);
    int len=strlen(s+1),cnt=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]!=')')
        {
            if(s[i]=='(') ++cnt;
            if(s[i]!=',') op[++qwq]=s[i];
        }
        else
        {
            int tot=0;
            while(op[qwq]!='(')
            {
                ans[++tot]=op[qwq];
                --qwq;
            }
            --qwq;
            if(cnt==n)
            {
                for(int i=tot;i>=1;i--)
                printf("%c ",ans[i]);
            }
            --cnt;
        }
    }
    return 0;
}