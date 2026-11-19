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

int idx=1,len,cnt=0,root;
char s[MAX];

int dfs()
{
    if(idx>len) return 0;
    char now=s[idx++];
    if(now=='#') return 0;
    op[++cnt].val=now;
    int pos=cnt;
    // printf("%d ",cnt);
    op[pos].l=dfs();
    op[pos].r=dfs();
    return pos;
}

void mid(int pos)
{
    if(!pos) return;
    mid(op[pos].l);
    printf("%c",op[pos].val);
    mid(op[pos].r);
}

int main()
{
    scanf(" %s",s+1);
    len=strlen(s+1);
    root=dfs();
    mid(root);
    return 0;
}