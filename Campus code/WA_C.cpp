#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int a[100010],b[100010];
int lena=0,lenb=0;

int main()
{
    int k;
    while(scanf("%d",&k)==1)
    {
        if(k==-1) break;
        a[++lena]=k;
    }
    while(scanf("%d",&k)==1)
    {
        if(k==-1) break;
        b[++lenb]=k;
    }
    bool f=true;
    for(int i=1,j=1;i<=lena&&j<=lenb;)
    {
        if(a[i]==b[j])
        {
            if(f) printf("%d",a[i]),f=false;
            else printf(" %d",a[i]);
            i++,j++;
            continue;
        }
        if(a[i]<b[j]) i++;
        else j++;
    }
    return 0;
}