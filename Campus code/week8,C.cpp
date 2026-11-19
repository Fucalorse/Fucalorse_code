#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX];

int main()
{
    scanf("%[^\n]%*c",s+1);
    int len=strlen(s+1);
    for(int i=len;i>=1;i--)
    {
        if(s[i]=='(') printf(")");
        else if(s[i]==')') printf("(");
        else printf("%c",s[i]);
    }
    return 0;
}