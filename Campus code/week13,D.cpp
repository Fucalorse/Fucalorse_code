#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define inf 2e9
#define LL long long

struct point
{
    int u,v,val;
}op[MAX],ans[MAX];
typedef struct point V;

V get(int u,int v,int val)
{
    V now;
    now.u=u,now.v=v,now.val=val;
    return now;
}

void swap(V *a,V *b)
{
    V p=*a;
    *a=*b;
    *b=p;
}

int qwq=0;

void up()
{
    int i=qwq,j=qwq>>1;
    while(j>=1)
    {
        if(op[j].val>op[i].val) swap(op+i,op+j);
        else break;
        i=j;
        j>>=1;
    }
}

void down()
{
    int i=1,j=2;
    while(j<=qwq)
    {
        if(j+1<=qwq&&op[j+1].val<op[j].val) j++;
        if(op[j].val<op[i].val) swap(op+i,op+j);
        else break;
        i=j;
        j<<=1;
    }
}

void push(V n)
{
    op[++qwq]=n;
    up();
}

void pop()
{
    op[1]=op[qwq--];
    down();
}

V top() { return op[1]; }

int size() { return qwq; }

int n,m,tot=0;
int g[100][100];
bool vis[MAX];
char s[MAX];

int bfs()
{
    V st=get(0,s[1]-'A'+1,0);
    push(st);
    int total=0;
    while(size())
    {
        V cur=top();pop();
        if(vis[cur.v]) continue;
        vis[cur.v]=true;
        total+=cur.val;
        if(cur.u&&cur.v) ans[++tot]=cur;
        for(int to=1;to<=n;to++)
            if(g[cur.v][to]!=inf)
            {
                V now=get(cur.v,to,g[cur.v][to]);
                push(now);
            }
    }
    return total;
}

void solve()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf(" %c",s+i);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j) g[i][j]=inf;
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        char a,b;
        int u,v,val;
        scanf(" %c%*c%c%*c%d",&a,&b,&val);
        u=a-'A'+1,v=b-'A'+1;
        g[u][v]=val;
        g[v][u]=val;
    }
    int total=bfs();
    if(tot==n-1)
    {
        for(int i=1;i<=tot;i++)
        {
            char u=ans[i].u+'A'-1,v=ans[i].v+'A'-1;
            if(u<v) printf("%c,%c:%d\n",u,v,ans[i].val);
            else printf("%c,%c:%d\n",v,u,ans[i].val);
        }
        printf("\n%d\n",total);
    }
    else printf("ERROR\n");
}

int main()
{
    solve();
    return 0;
}