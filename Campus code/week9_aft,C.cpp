#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

struct tree
{
    int val,l,r;
}op[MAX];

int root,qwq;
int f[40];
char pre[MAX],mid[MAX];

int update(int pos,int k)
{
    if(!pos)
    {
        op[++qwq].val=k;
        op[qwq].l=op[qwq].r=0;
        return qwq;
    }
    if(k<op[pos].val) op[pos].l=update(op[pos].l,k);
    else op[pos].r=update(op[pos].r,k);
    return pos;
}

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    print(op[pos].r);
    printf("%c",mid[op[pos].val]);
}

int main()
{
    while(scanf(" %s %s",pre+1,mid+1)==2)
    {
        qwq=root=0;
        int len=strlen(pre+1);
        for(int i=1;i<=len;i++)
            f[mid[i]-'A']=i;
        for(int i=1;i<=len;i++)
            root=update(root,f[pre[i]-'A']);
        print(root);
        printf("\n");
    }
    return 0;
}