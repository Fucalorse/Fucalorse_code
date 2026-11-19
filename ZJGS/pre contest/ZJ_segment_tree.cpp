#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=1e5+90;
const LL mod=998244353;

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

int n,m,q;

struct fucalorse
{
    private:
        struct qwq
        {
            LL f[5][5];
        }op[MAX<<2];
        qwq merge(const qwq &a,const qwq &b)
        {
            qwq T;
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                {
                    T.f[i][j]=0;
                    for(int k=1;k<=3;k++)
                        T.f[i][j]=(T.f[i][j]+b.f[i][k]*a.f[k][j])%mod;
                }
            return T;
        }
        void dfs(int l,int r,int id,const int &x,const int &i,const int &j)
        {
            if(l==r)
            {
                op[id].f[j][i]=1-op[id].f[j][i];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,i,j);
            else dfs(mid+1,r,hr,x,i,j);
            op[id]=merge(op[hl],op[hr]);
        }
    public:
        void update(const int &x,const int &i,const int &j)
        {
            dfs(1,n-1,1,x,i,j);
        }
        LL query(const LL &a,const LL &b,const LL &c)
        {
            LL num1=(op[1].f[1][1]+op[1].f[2][1]+op[1].f[3][1])%mod;
            LL num2=(op[1].f[1][2]+op[1].f[2][2]+op[1].f[3][2])%mod;
            LL num3=(op[1].f[1][3]+op[1].f[2][3]+op[1].f[3][3])%mod;
            return (a%mod*num1+b%mod*num2+c%mod*num3)%mod;
        }
}fu;

int main()
{
    n=read(),m=read(),q=read();
    for(int s=1;s<=m;s++)
    {
        int x=read(),i=read(),j=read();
        fu.update(x,i,j);
    }
    while(q--)
    {
        char c;
        scanf(" %c",&c);
        if(c=='d')
        {
            int x=read(),i=read(),j=read();
            fu.update(x,i,j);
        }
        else
        {
            LL a=read(),b=read(),c=read();
            printf("%lld\n",fu.query(a,b,c));
        }
    }
    return 0;
}