#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX];
int a[MAX],b[MAX],lena=0,lenb=0;

int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        if(isdigit(s[i])) b[++lenb]=s[i];
        else a[++lena]=s[i];
    }
    for(int i=1;i<=lena/2;i++)
        printf("%c",a[i]);
    for(int i=1;i<=lenb;i++)
        printf("%c",b[i]);
    for(int i=lena/2+1;i<=lena;i++)
        printf("%c",a[i]);
    return 0;
}