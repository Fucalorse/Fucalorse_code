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
    scanf(" %s",s+1);
    len=strlen(s+1);
    for(int i=1;i<=len/2;i++)
        if(s[i]!=s[len-i+1])
        {
            printf("不是回文");
            exit(0);
        }
    printf("是回文");
    return 0;
}