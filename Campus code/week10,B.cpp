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
}op[1000];

int t,qwq=0,root,depth[MAX],cnt[1000],maxn;
char st[MAX],s[MAX];

int max(int a,int b) { return a>b?a:b; }

void dfs(int ch,int fa)
{
    if(!ch) return;
    depth[ch]=depth[fa]+1;
    cnt[depth[ch]]++;
    maxn=max(maxn,depth[ch]);
    // printf("%c %c %c\n",ch,op[ch].l,op[ch].r);
    dfs(op[ch].l,ch);
    dfs(op[ch].r,ch);
}

char top()
{
    for(int i=qwq;i>=1;i--)
        if(isupper(st[i])||islower(st[i])) return st[i];
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(op,0,sizeof(op)),memset(cnt,0,sizeof(cnt));
        qwq=0,root=0,maxn=0;

        scanf(" %s",s+1);
        int len=strlen(s+1),pos=0;
        for(int i=1;i<=len;i++)
        {
            if(s[i]=='(')
            {
                st[++qwq]=s[i];
                pos=0;
            }
            else if(s[i]==',')
            {
                pos=1;
                if(st[qwq]!='(') --qwq;
            }
            else if(s[i]==')')
            {
                while(qwq&&st[qwq]!='(') --qwq;
                --qwq;
            }
            else
            {
                if(!root) root=s[i];
                else
                {
                    if(pos==0) op[top()].l=s[i];
                    else op[top()].r=s[i];
                    // printf("%c %c\n",top(),s[i]);
                }
                st[++qwq]=s[i];
                // printf("%c\n",s[i]);
            }
        }
        depth[0]=-1;
        dfs(root,0);
        // printf("%d\n",maxn);
        LL ans=0;
        for(int i=0;i<=maxn;i++)
        {
            ans+=(LL)cnt[i]*i;
            // printf("%d\n",cnt[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}