#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=17;

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

int n,q;
int f[MAX][LEN+2];
struct fucalorse
{
    void create()
    {
        for(int i=1;i<=n;i++)
            f[i][0]=read();
        for(int k=1;k<=LEN;k++)
            for(int i=1;i+(1<<k)-1<=n;i++)
                f[i][k]=max(f[i][k-1],f[i+(1<<(k-1))][k-1]);
    }
    int query(const int &st,const int &ed)
    {
        int k=log2(ed-st+1);
        return max(f[st][k],f[ed-(1<<k)+1][k]);
    }
}fu;

int main()
{
    n=read(),q=read();
    fu.create();
    while(q--)
    {
        int st=read(),ed=read();
        printf("%d\n",fu.query(st,ed));
    }
    return 0;
}