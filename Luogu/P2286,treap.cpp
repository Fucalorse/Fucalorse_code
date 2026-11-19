#include <bits/stdc++.h>
using namespace std;

const int mod=1e6,inf=2e9;

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
    int val,size,cnt,pri;
    qwq *l,*r;
    qwq(int k):val(k),size(1),cnt(1),
    pri(dist(rng)),l(nullptr),r(nullptr){}
};

struct tree
{
    void maintain(qwq *pos)
    {
        if(pos)
        {
            pos->size=pos->cnt;
            if(pos->l) pos->size+=pos->l->size;
            if(pos->r) pos->size+=pos->r->size;
        }
    }
    pair<qwq*,qwq*> split(qwq *pos,const int &k)
    {
        if(!pos) return {nullptr,nullptr};
        if(pos->val<k)
        {
            auto p=split(pos->r,k);
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
    qwq *insert(qwq *pos,qwq *node)
    {
        if(!pos) return node;
        if(pos->val==node->val)
        {
            pos->size++;
            pos->cnt++;
            delete(node);
            return pos;
        }
        if(node->pri>pos->pri)
        {
            auto p=split(pos,node->val);
            qwq *left=p.first,*right=p.second;
            node->l=left,node->r=right;
            maintain(node);
            return node;
        }
        if(node->val<pos->val) pos->l=insert(pos->l,node);
        else pos->r=insert(pos->r,node);
        maintain(pos);
        return pos;
    }
    qwq *remove(qwq *pos,const int &k)
    {
        if(!pos) return nullptr;
        if(pos->val==k)
        {
            if(pos->cnt>1)
            {
                pos->size--;
                pos->cnt--;
                return pos;
            }
            qwq *res=merge(pos->l,pos->r);
            delete(pos);
            return res;
        }
        if(k<pos->val) pos->l=remove(pos->l,k);
        else pos->r=remove(pos->r,k);
        maintain(pos);
        return pos;
    }
    int predecessor(qwq *pos,const int &k)
    {
        if(!pos) return -inf;
        if(pos->val<k) return max(pos->val,predecessor(pos->r,k));
        else return predecessor(pos->l,k);
    }
    int successor(qwq *pos,const int &k)
    {
        if(!pos) return inf;
        if(k<=pos->val) return min(pos->val,successor(pos->l,k));
        else return successor(pos->r,k);
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
};

struct fucalorse
{
    tree op;
    qwq *root;
    fucalorse() { root=nullptr; }
    ~fucalorse() { op.clear(root); }
    bool empty() { return !root;}
    void update(const int &val) { root=op.insert(root,new qwq(val)); }
    void remove(const int &val) { root=op.remove(root,val); }
    int predecessor(const int &val) { return op.predecessor(root,val); }
    int successor(const int &val) { return op.successor(root,val); }
}fu;

int main()
{
    int n=read(),cur,ans=0;
    for(int i=1;i<=n;i++)
    {
        int p=read(),x=read();
        if(fu.empty())
        {
            cur=p;
            fu.update(x);
        }
        else if(cur==p) fu.update(x);
        else
        {
            int pre=fu.predecessor(x),aft=fu.successor(x);
            if(pre==-inf)
            {
                ans+=aft-x;
                fu.remove(aft);
            }
            else if(aft==inf)
            {
                ans+=x-pre;
                fu.remove(pre);
            }
            else
            {
                if(x-pre<=aft-x)
                {
                    ans+=x-pre;
                    fu.remove(pre);
                }
                else
                {
                    ans+=aft-x;
                    fu.remove(aft);
                }
            }
            ans%=mod;
        }
    }
    printf("%d\n",ans);
    return 0;
}