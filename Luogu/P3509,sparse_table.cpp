#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e6+90;

LL read()
{
    LL ans=0,f=1;
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

int n,k;
LL m,op[MAX];
int ans[MAX],f[MAX],pre[MAX];
struct fucalorse
{
    void monotonous()
    {
        int l=1,r=k+1;
        for(int i=1;i<=n;i++)
        {
            while(r+1<=n&&op[r+1]-op[i]<op[i]-op[l]) l++,r++;
            if(op[i]-op[l]>=op[r]-op[i]) f[i]=l;
            else f[i]=r;
            ans[i]=i;
        }
    }
    void create()
    {
        monotonous();
        while(m)
        {
            if(m&1)
            {
                for(int i=1;i<=n;i++)
                    ans[i]=f[ans[i]];
            }
            memcpy(pre,f,sizeof f);
            for(int i=1;i<=n;i++)
                f[i]=pre[pre[i]];
            m>>=1;
        }
    }
}fu;

int main()
{
    n=read(),k=read(),m=read();
    for(int i=1;i<=n;i++)
        op[i]=read();
    fu.create();
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}