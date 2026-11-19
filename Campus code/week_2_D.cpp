#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

char s[MAX],t[MAX],rep[MAX];
bool f[MAX];
int op[MAX];
int len1,len2;

void create()
{
    for(int i=1,j=0;i<len2;i++)
    {
        while(j&&t[i]!=t[j]) j=op[j];
        if(t[i]==t[j]) j++;
        op[i+1]=j;
    }
}

bool find()
{
    bool ans=false;
    for(int i=0,j=0;i<len1;i++)
    {
        while(j&&s[i]!=t[j]) j=op[j];
        if(s[i]==t[j]) j++;
        if(j==len2)
        {
            f[i-len2+1]=true;
            ans=true;
            j=0;
        }
    }
    return ans;
}

int main()
{
    scanf(" %s %s %s",s,t,rep);
    len1=strlen(s),len2=strlen(t);
    create();
    if(find())
    {
        for(int i=0;i<len1;i++)
        {
            if(f[i]) printf("%s",rep),i+=len2-1;
            else printf("%c",s[i]);
        }
    }
    else printf("NO");
    return 0;
}