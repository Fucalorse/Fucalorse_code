#include <bits/stdc++.h>
using namespace std;

const int MAX=6e5+90,LEN=24;

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
    qwq *op[2];
    int cnt;
    qwq() { op[0]=op[1]=nullptr,cnt=0; }
};

struct fucalorse
{
    vector<qwq*>ver;
    fucalorse() { ver.push_back(new qwq); }
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
    void update(const int &sum)
    {
        qwq *now=clone(ver.back()),*pre=ver.back();
        ver.push_back(now);
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1;
            qwq *old=pre?pre->op[p]:nullptr;
            qwq *aft=clone(old);
            now->op[p]=aft;
            if(aft) aft->cnt++;
            now=aft;
            if(pre) pre=pre->op[p];
        }
    }
    int query(const int &st,const int &ed,const int &sum)
    {
        qwq *l=ver[st],*r=ver[ed];
        int ans=0;
        for(int i=LEN;i>=0;i--)
        {
            int p=(sum>>i)&1,aft=p;
            int numl=l&&l->op[p^1]?l->op[p^1]->cnt:0;
            int numr=r&&r->op[p^1]?r->op[p^1]->cnt:0;
            if(numr-numl>0)
            {
                ans|=1<<i;
                aft=p^1;
            }
            if(l) l=l->op[aft];
            if(r) r=r->op[aft];
        }
        return ans;
    }
}fu;

int n,q;

int main()
{
    n=read(),q=read();
    int sum=0;
    fu.update(sum);
    for(int i=1;i<=n;i++)
    {
        sum=sum^read();
        fu.update(sum);
    }
    while(q--)
    {
        char c;
        scanf(" %c",&c);
        if(c=='A')
        {
            sum=sum^read();
            fu.update(sum);
        }
        else
        {
            int l=read(),r=read(),x=sum^read();
            printf("%d\n",fu.query(l-1,r,x));
        }
    }
    return 0;
}