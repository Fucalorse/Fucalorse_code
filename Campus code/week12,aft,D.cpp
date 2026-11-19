#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char s[MAX];
int op[MAX],nxt[MAX];

int main()
{
    scanf(" %s",s);
    int len=strlen(s);
    for(int i=1,j=0;i<len;i++)
    {
        while(j&&s[i]!=s[j]) j=op[j];
        if(s[i]==s[j]) j++;
        op[i+1]=j;
    }
    for(int i=2;i<=len;i++)
        nxt[i]=op[i-1]+1;
    for(int i=1;i<=len;i++)
    {
        if(i>1) printf(" ");
        printf("%d",nxt[i]);
    }
    printf("\n");
    return 0;
}