#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

int len;
char s[MAX];

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        len=strlen(s+1);
        int a=len/2,b=(len+1)/2+1;
        for(int i=a;i>=1;i--)
            printf("%c",s[i]);
        if(len&1) printf("%c",s[(len+1)/2]);
        for(int i=len;i>=b;i--)
            printf("%c",s[i]);
        printf("\n\n");
    }
    return 0;
}