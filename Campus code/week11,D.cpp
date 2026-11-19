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
    int l,r;
}op[MAX];

int qwq=0,root=0,maxn=0;
int f[MAX],depth[MAX];
char s[MAX],st[MAX];

bool dis(char c) { return islower(c)||isupper(c); }

int max(int a,int b) { return a>b?a:b; }

char get()
{
    for(int i=qwq;i>=1;i--)
        if(dis(st[i])) return st[i];
    return 'A';
}

int to(char c) { return c-'A'+1; }

void dfs(int ch,int fa)
{
    // printf("%d %d\n",ch,fa);
    depth[ch]=depth[fa]+1;
    // printf("%d %d\n",ch,depth[ch]);
    f[depth[ch]]++;
    maxn=max(maxn,depth[ch]);
    if(op[ch].l) dfs(op[ch].l,ch);
    if(op[ch].r) dfs(op[ch].r,ch);
}

int main()
{
    scanf(" %s",s+1);
    int n=strlen(s+1),pos=0;
    for(int i=1;i<=n;i++)
    {
        if(dis(s[i]))
        {
            if(!root) root=to(s[i]);
            if(qwq)
            {
                if(pos) op[to(get())].r=to(s[i]);
                else op[to(get())].l=to(s[i]);
            }
            st[++qwq]=s[i];
        }
        else if(s[i]=='(') st[++qwq]=s[i],pos=0;
        else if(s[i]==',')
        {
            if(dis(st[qwq])) --qwq;
            pos=1;
        }
        else
        {
            while(st[qwq]!='(') --qwq;
            --qwq;
        }
    }
    dfs(root,0);
    int ans=0;
    for(int i=1;i<=maxn;i++)
        ans=max(ans,f[i]);
    printf("%d %d\n",maxn,ans);
    return 0;
}