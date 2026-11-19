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

struct fucalorse
{
    private:
        struct qwq
        {
            qwq *op[2];
            int cnt;
            qwq() { op[0]=op[1]=nullptr,cnt=0;}
        };
        vector<qwq*>ver;
        qwq *clone(qwq *node)
        {
            qwq *now=new qwq;
            if(node)
            {
                now->op[0]=node->op[0];
                now->op[1]=node->op[1];
                now->cnt=node->cnt;
            }
            return now;
        }
    public:
        fucalorse() { ver.push_back(new qwq); }
        void update(const LL &sum)
        {
            qwq *now=clone(ver.back()),*pre=ver.back();
            ver.push_back(now);
            for(int i=LEN;i>=0;i--)
            {
                int p=(sum>>i)&1;
                qwq *old=pre&&pre->op[p]?pre->op[p]:nullptr;
                qwq *aft=clone(old);
                now->op[p]=aft;
                aft->cnt++;
                now=aft;
                if(pre) pre=pre->op[p];
            }
        }
        LL query(const int &st,const LL &sum,int k)
        {
            qwq *l=ver[st],*r=ver.back();
            LL ans=0;
            for(int i=LEN;i>=0;i--)
            {
                int p=(sum>>i)&1;
                int numl=l&&l->op[p^1]?l->op[p^1]->cnt:0;
                int numr=r&&r->op[p^1]?r->op[p^1]->cnt:0;
                int d=numr-numl,aft=p;
                if(d>0)
                {
                    if(k<=d)
                    {
                        ans|=1LL<<i;
                        aft=p^1;
                    }
                    else k-=d;
                }
                if(l) l=l->op[aft];
                if(r) r=r->op[aft];
            }
            return ans;
        }
}fu;

struct qwq
{
    LL val;
    int pre,pos;
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
        f[i]=f[i-1]^read();
        fu.update(f[i]);
    }
    for(int i=1;i<=n;i++)
    {
        LL now=fu.query(i,f[i-1],1);
        q.push({now,1,i});
    }
    LL total=0;
    for(int i=1;i<=k;i++)
    {
        qwq cur=q.top();q.pop();
        total+=cur.val;
        LL aft=fu.query(cur.pos,f[cur.pos-1],cur.pre+1);
        q.push({aft,cur.pre+1,cur.pos});
    }
    printf("%lld\n",total);
    return 0;
}