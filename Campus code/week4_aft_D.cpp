#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX];

int cmp(const void *a,const void *b)
{
    const char x=*(const char*)a,y=*(const char*)b;
    return x-y;
}

int main()
{
    scanf(" %s",s);
    int len=strlen(s);
    qsort(s,len,sizeof(char),cmp);
    printf("%s",s);
    return 0;
}