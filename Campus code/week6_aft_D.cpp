#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 10090

char s[MAX];

int main()
{
    while(scanf("%[^\n]%*c",s)==1)
    {
        int len=strlen(s),qwq=0;
        s[len-1]='\0';
        char *op[100],*now=strtok(s+1," ");
        while(now!=NULL)
        {
            op[++qwq]=now;
            now=strtok(NULL," ");
        }
        putchar('"');
        for(int i=qwq;i>=1;i--)
        {
            if(i<qwq) printf(" ");
            printf("%s",op[i]);
        }
        putchar('"');
        printf("\n");
    }
    return 0;
}