#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,LEN=19;

int read()
{
    int ans=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        ans=ans*10+c-'0';
        c=getchar();
    }
    return ans*f;
}

struct qwq
{
    int st,ed,id;
    bool operator<(const qwq &a)const { return st<a.st; }
}op[MAX<<1];
int n,m;
int f[MAX<<1][LEN+2],ans[MAX];

struct fucalorse
{
    void create()
    {
        int size=n<<1;
        for(int l=1,r=1;l<=size;l++)
        {
            while(r<=size&&op[r].st<=op[l].ed) r++;
            f[l][0]=r-1;
        }
        for(int k=1;(1<<k)<=size;k++)
            for(int i=1;i+(1<<k)<=size;i++)
                f[i][k]=f[f[i][k-1]][k-1];
    }
    void query(const int &i)
    {
        int len=op[i].ed+m,pos=i,cnt=0;
        for(int k=LEN;k>=0;k--)
        {
            int aft=f[pos][k];
            if(aft&&op[aft].ed<len)
            {
                cnt+=1<<k;
                pos=f[pos][k];
            }
        }
        ans[op[i].id]=cnt+1;
    }
}fu;

int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        op[i].st=read(),op[i].ed=read();
        if(op[i].ed<op[i].st) op[i].ed+=m;
        op[i].id=i;
    }
    sort(op+1,op+n+1);
    for(int i=1;i<=n;i++)
        op[i+n]={op[i].st+m,op[i].ed+m,op[i].id};
    fu.create();
    for(int i=1;i<=n;i++)
        fu.query(i);
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}