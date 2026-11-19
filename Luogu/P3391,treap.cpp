#include <bits/stdc++.h>
using namespace std;

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

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    int val,size,pri;
    bool lazy;
    qwq *l,*r;
    qwq(int k):val(k),size(1),pri(dist(rng)),lazy(false),
    l(nullptr),r(nullptr){}
};

struct tree
{
    void maintain(qwq *pos)
    {
        if(pos)
        {
            pos->size=1;
            if(pos->l) pos->size+=pos->l->size;
            if(pos->r) pos->size+=pos->r->size;
        }
    }
    void down(qwq *pos)
    {
        if(pos->lazy)
        {
            swap(pos->l,pos->r);
            if(pos->l) pos->l->lazy^=1;
            if(pos->r) pos->r->lazy^=1;
            pos->lazy=false;
        }
    }
    pair<qwq*,qwq*> split(qwq *pos,int k)
    {
        if(!pos) return {nullptr,nullptr};
        down(pos);
        int num=pos->l?pos->l->size:0;
        if(num+1<=k)
        {
            auto p=split(pos->r,k-num-1);
            qwq *left=p.first,*right=p.second;
            pos->r=left;
            maintain(pos);
            return {pos,right};
        }
        else
        {
            auto p=split(pos->l,k);
            qwq *left=p.first,*right=p.second;
            pos->l=right;
            maintain(pos);
            return {left,pos};
        }
    }
    qwq *merge(qwq *left,qwq *right)
    {
        if(!left||!right) return left?left:right;
        down(left),down(right);
        if(left->pri>right->pri)
        {
            left->r=merge(left->r,right);
            maintain(left);
            return left;
        }
        else
        {
            right->l=merge(left,right->l);
            maintain(right);
            return right;
        }
    }
    void clear(qwq *pos)
    {
        if(!pos) return;
        queue<qwq*>q;
        q.push(pos);
        while(q.size())
        {
            qwq *cur=q.front();q.pop();
            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
            delete(cur);
        }
    }
    void print(qwq *pos)
    {
        if(!pos) return;
        down(pos);
        print(pos->l);
        printf("%d ",pos->val);
        print(pos->r);
    }
};

struct fucalorse
{
    tree op;
    qwq *root;
    fucalorse() { root=nullptr; }
    ~fucalorse() {op.clear(root); }
    void update(const int &val)
    {
        root=op.merge(root,new qwq(val));
    }
    void change(const int &st,const int &ed)
    {
        auto p=op.split(root,ed);
        auto q=op.split(p.first,st-1);
        if(q.second) q.second->lazy^=1;
        root=op.merge(q.first,q.second);
        root=op.merge(root,p.second);
    }
    void applause() { op.print(root); }
}fu;

int main()
{
    int n,k;
    n=read(),k=read();
    for(int i=1;i<=n;i++)
        fu.update(i);
    while(k--)
    {
        int st=read(),ed=read();
        fu.change(st,ed);
    }
    fu.applause();
    printf("\n");
    return 0;
}