#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090

struct ovo
{
    int l,r,val;
}op[MAX];

int n,head=0,tail=0,qwq=0;
char s[20];

void update(int pos)
{
    if(!head)
    {
        head=tail=++qwq;
        scanf("%d",&op[qwq].val);
        return;
    }
    int cnt=0;
    bool f=false;
    for(int i=head;i;i=op[i].r)
        if(++cnt==pos)
        {
            if(i==head)
            {
                op[++qwq].r=head;
                op[head].l=qwq;
                head=qwq;
                scanf("%d",&op[qwq].val);
                f=true;
            }
            else
            {
                ++qwq;
                op[qwq].l=op[i].l,op[qwq].r=i;
                op[op[i].l].r=qwq;
                op[i].l=qwq;
                scanf("%d",&op[qwq].val);
                f=true;
            }
            break;
        }
    if(!f)
    {
        op[++qwq].l=tail;
        op[tail].r=qwq;
        tail=qwq;
        scanf("%d",&op[qwq].val);
    }
}

int del(int pos)
{
    int cnt=0,ans=0;
    for(int i=head;i;i=op[i].r)
        if(++cnt==pos)
        {
            ans=op[i].val;
            if(i==head) head=op[head].r,op[head].l=0;
            else if(i==tail) tail=op[tail].l,op[tail].r=0;
            else
            {
                op[op[i].l].r=op[i].r;
                op[op[i].r].l=op[i].l;
            }
        }
    return ans;
}

int find(int pos)
{
    int cnt=0;
    for(int i=head;i;i=op[i].r)
        if(++cnt==pos) return op[i].val;
    return -1;
}

void print()
{
    for(int i=head;i;i=op[i].r)
        printf("%d ",op[i].val);
    printf("\n");
}

void clear()
{
    qwq=head=tail=0;
    memset(op,0,sizeof op);
}

int main()
{
    while(scanf(" %s",s)==1)
    {
        if(s[0]=='e') break;
        if(s[0]=='i')
        {
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
            {
                int id;
                scanf("%d",&id);
                update(id);
            }
        }
        else if(s[0]=='d')
        {
            int id;
            scanf("%d",&id);
            printf("%d\n",del(id));
        }
        else if(s[0]=='c') clear();
        else
        {
            int id;
            scanf("%d",&id);
            // print(); 
            printf("%d\n",find(id));
        }
    }
    return 0;
}