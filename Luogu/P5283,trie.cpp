#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=5e5+90,LEN=32;

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

struct ovo
{
    ovo *op[2];
    int cnt;
    ovo() { op[0]=op[1]=nullptr,cnt=0; }
};

struct fucalorse
{
    ovo *root=new ovo;
    void update(const LL &sum)
    {
        ovo *now=root;
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1;
            if(!now->op[p]) now->op[p]=new ovo;
            now=now->op[p];
            now->cnt++;
        }
    }
    LL query(const LL &sum,int k)
    {
        ovo *now=root;
        LL ans=0;
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1LL;
            if(!now->op[p^1]) now=now->op[p];
            else
            {
                int num=now->op[p^1]->cnt;
                if(k<=num)
                {
                    ans|=1LL<<i;
                    now=now->op[p^1];
                }
                else
                {
                    now=now->op[p];
                    k-=num;
                }
            }
        }
        return ans;
    }
}fu;

struct qwq
{
    LL val;
    int pos,pre;
    bool operator<(const qwq &a)const { return val<a.val; }
};

int n,k;
LL f[MAX];
priority_queue<qwq>q;

int main()
{
    n=read(),k=read();
    fu.update(f[0]);
    for(int i=1;i<=n;i++)
    {
        f[i]=read()^f[i-1];
        fu.update(f[i]);
    }
    for(int i=0;i<=n;i++)
        q.push({fu.query(f[i],1),i,1});
    LL total=0;
    for(int i=1;i<=2*k;i++)
    {
        qwq cur=q.top();q.pop();
        total+=cur.val;
        q.push({fu.query(f[cur.pos],cur.pre+1),cur.pos,cur.pre+1});
    }
    printf("%lld\n",total>>1);
    return 0;
}