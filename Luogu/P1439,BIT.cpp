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

struct peach
{
    private:
        int op[MAX<<1],size;
        int lowbit(int n) { return n&-n; }
    public:
        peach(int n) { size=n; }
        void update(int n,const int &k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=lowbit(n);
            }
        }
        int query(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=op[n];
                n-=lowbit(n);
            }
            return ans;
        }
};

int n;
int pre[MAX],num[MAX],op[MAX],qwq=0;
unordered_map<int,int>f;

int main()
{
    n=read();
    peach fu(n);
    for(int i=1,cnt=0;i<=n;i++)
        pre[i]=read(),f[pre[i]]=++cnt;
    for(int i=1;i<=n;i++)
    {
        int a=read();
        num[i]=f[a];
    }
    for(int i=1;i<=n;i++)
    {
        int pos=fu.query(num[i])+1;
        if(pos>qwq) qwq=pos;
        else fu.update(op[pos],-1);
        fu.update(num[i],1);
        op[pos]=num[i];
    }
    printf("%d\n",qwq);
    return 0;
}