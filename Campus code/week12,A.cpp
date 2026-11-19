#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100090
#define LL long long

int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

struct point
{
    int x,y;
}q[MAX];
typedef struct point qwq;

int h,t;

void initial() { h=1,t=0; }

void push(qwq n) { q[++t]=n; }
qwq front() { return q[h]; }
void pop() { ++h; }
int size() { return t-h+1; }

int T;
char s[100][100];
bool vis[100][100];

bool dis(int i,int j) { return i>=0&&i<=4&&j>=0&&j<=4&&s[i][j]!='*'; }

bool bfs(qwq st,qwq ed)
{
    initial();
    memset(vis,false,sizeof(vis));
    push(st);
    vis[st.x][st.y]=true;
    // for(int i=0;i<=4;i++)
    // {
    //     for(int j=0;j<=4;j++)
    //         printf("%c",s[i][j]);
    //     printf("\n");
    // }
    while(size())
    {
        qwq cur=front();pop();
        if(cur.x==ed.x&&cur.y==ed.y) return true;
        for(int s=0;s<4;s++)
        {
            int nx=cur.x+dx[s],ny=cur.y+dy[s];
            if(dis(nx,ny)&&!vis[nx][ny])
            {
                vis[nx][ny]=true;
                qwq now={nx,ny};
                push(now);
            }
        }
    }
    return false;
}

void solve()
{
    qwq st,ed;
    scanf("%d%d%d%d",&st.x,&st.y,&ed.x,&ed.y);
    for(int i=0;i<=4;i++)
        for(int j=0;j<=4;j++)
            scanf(" %c",&s[i][j]);
    if(bfs(st,ed)) printf("YES\n");
    else printf("NO\n");
}

int main()
{
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}