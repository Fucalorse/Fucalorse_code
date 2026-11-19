#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 10090

struct ovo
{
    char w[25];
    int pri;
    int l,r;
}op[MAX];

int root,qwq=0;
char now[25],id[25];

int update(int pos,char *s)
{
    if(!pos)
    {
        strcpy(op[++qwq].w,s);
        op[qwq].pri=21312;
        return qwq;
    }
    if(strcmp(s,op[pos].w)<0) op[pos].l=update(op[pos].l,s);
    else op[pos].r=update(op[pos].r,s);
    return pos;
}

int merge(int left,int right)
{
    if(!left||!right) return left?left:right;
    if(op[left].pri>op[right].pri)
    {
        op[left].r=merge(op[left].r,right);
        return left;
    }
    else
    {
        op[right].l=merge(left,op[right].l);
        return right;
    }
}

int del(int pos,char *s)
{
    if(!pos) return 0;
    if(strcmp(op[pos].w,s)==0)
    {
        int res=merge(op[pos].l,op[pos].r);
        return res;
    }
    if(strcmp(s,op[pos].w)<0) op[pos].l=del(op[pos].l,s);
    else op[pos].r=del(op[pos].r,s);
    return pos;
}

bool find(int pos,char *s)
{
    if(!pos) return false;
    if(strcmp(op[pos].w,s)==0) return true;
    if(strcmp(s,op[pos].w)<0) return find(op[pos].l,s);
    else return find(op[pos].r,s);
}

void print(int pos)
{
    if(!pos) return;
    print(op[pos].l);
    printf("%s\n",op[pos].w);
    print(op[pos].r);
}

int main()
{
    while(scanf(" %s",id)!=EOF)
    {
        if(id[0]=='A')
        {
            scanf(" %s",now);
            root=update(root,now);
        }
        else if(id[0]=='D')
        {
            scanf(" %s",now);
            root=del(root,now);
        }
        else if(id[0]=='Q')
        {
            scanf(" %s",now);
            if(find(root,now)) printf("Yes\n");
            else printf("No\n");
        }
        else print(root);
    }
    return 0;
}