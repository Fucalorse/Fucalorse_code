#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq=0;
char op[MAX],s[MAX];

int main()
{
    scanf(" %s",s+1);
    int len=strlen(s+1),i=1;
    while(i<=len)
    {
        if(s[i]=='&') break;
        op[++qwq]=s[i++];
    }
    if(len-i!=qwq)
    {
        printf("NO");
        exit(0);
    }
    int j=qwq;
    for(i=i+1;i<=len&&j>=1;i++,j--)
        if(op[j]!=s[i])
        {
            printf("NO");
            exit(0);
        }
    printf("YES");
    return 0;
}