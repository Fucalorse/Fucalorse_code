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
    char val;
    int l,r;
}op[MAX];

int t,idx,len,qwq;
char s[MAX];

int dfs()
{
    if(idx>len) return 0;
    char now=s[idx++];
    if(now=='#') return 0;
    op[++qwq].val=now;
    int pos=qwq;
    op[pos].l=dfs();
    op[pos].r=dfs();
    return pos;
}

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    printf("%c",op[pos].val);
    print(op[pos].r);
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %s",s+1);
        len=strlen(s+1);
        idx=1,qwq=0;
        int root=dfs();
        print(root);
        printf("\n");
    }
    return 0;
}