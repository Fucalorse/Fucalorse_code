#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int q[MAX];
int h,t;

void initial() { h=0,t=-1; }

void push(int n) { q[++t]=n; }

void pop() { ++h; }

int size() { return t-h+1; }

int front() { return q[h]; }

 struct tree
{
    char val;
    int l,r;
}op[MAX];

int idx,qwq,len;
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

void mid(int pos)
{
    if(!pos) return;
    mid(op[pos].l);
    printf("%c",op[pos].val);
    mid(op[pos].r);
}

void suf(int pos)
{
    if(!pos) return;
    suf(op[pos].l);
    suf(op[pos].r);
    printf("%c",op[pos].val);
}

void bfs(int now)
{
    initial();
    push(now);
    while(size())
    {
        int cur=front();pop();
        printf("%c",op[cur].val);
        if(op[cur].l) push(op[cur].l);
        if(op[cur].r) push(op[cur].r);
    }
}

int main()
{
    while(scanf(" %s",s+1)==1)
    {
        idx=1,qwq=0;
        len=strlen(s+1);
        int root=dfs();
        mid(root);
        printf(" ");
        suf(root);
        printf(" ");
        bfs(root);
        printf("\n");
    }
    return 0;
}