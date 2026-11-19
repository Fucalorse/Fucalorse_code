#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int qwq=0;
char s[MAX],op[MAX];

int main()
{
    scanf("%[^\n]%*c",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='@') qwq=0;
        else if(s[i]=='#') --qwq;
        else op[++qwq]=s[i];
    }
    for(int i=1;i<=qwq;i++)
        printf("%c",op[i]);
    return 0;
}