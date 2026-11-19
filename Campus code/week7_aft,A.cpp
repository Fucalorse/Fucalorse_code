#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char op[MAX],s[MAX];
bool vis[MAX];

int main()
{
    scanf("%[^\n]%*c%[^\n]%*c",op+1,s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
        vis[s[i]]=true;
    len=strlen(op+1);
    for(int i=1;i<=len;i++)
    {
        if(vis[op[i]]) continue;
        printf("%c",op[i]);
    }
    return 0;
}