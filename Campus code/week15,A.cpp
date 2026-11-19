#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

char s[MAX];

int cmp(const void *a,const void *b)
{
    const char x=*(const char *)a;
    const char y=*(const char *)b;
    return x-y;
}

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        int len=strlen(s+1);
        qsort(s+1,len/2,sizeof(char),cmp);
        for(int i=(len+1)/2+1;i<=len;i++)
            printf("%c",s[i]);
        if(len&1) printf("%c",s[(len+1)/2]);
        for(int i=1;i<=len/2;i++)
            printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}