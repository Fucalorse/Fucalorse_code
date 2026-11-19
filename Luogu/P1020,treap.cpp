#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    int val,size,pri;
    qwq *l,*r;
    qwq(int k):val(k),size(1),pri(dist(rng)),
    l(nullptr),r(nullptr){}
};

struct peach
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
        if(node->pri>pos->pri)
        {
            auto p=split(pos,node->val);
            node->l=p.first,node->r=p.second;
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
            qwq *res=merge(pos->l,pos->r);
            delete(pos);
            return res;
        }
        if(k<pos->val) pos->l=remove(pos->l,k);
        else pos->r=remove(pos->r,k);
        maintain(pos);
        return pos;
    }
    pair<int,qwq*> successor(qwq *pos,const int &k)
    {
        pair<int,qwq*>ans={INT_MAX,nullptr};
        while(pos)
        {
            if(pos->val>k)
            {
                if(pos->val<ans.first) ans={pos->val,pos};
                pos=pos->l;
            }
            else pos=pos->r;
        }
        return ans;
    }
};

struct fucalorse
{
    peach op;
    qwq *root;
    fucalorse() { root=nullptr; }
    void upper_bound(const int &val)
    {
        auto now=op.successor(root,val);
        if(now.second==nullptr) root=op.insert(root,new qwq(val));
        else
        {
            root=op.remove(root,now.first);
            root=op.insert(root,new qwq(val));
        }
    }
    void lower_bound(const int &val)
    {
        auto now=op.successor(root,val-1);
        if(now.second==nullptr) root=op.insert(root,new qwq(val));
        else
        {
            root=op.remove(root,now.first);
            root=op.insert(root,new qwq(val));            
        }
    }
    int get() { return root?root->size:0; }
}fu,fufu;

int n;
int num[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int val;
    while(cin>>val) num[++n]=val;
    for(int i=n;i>=1;i--) fu.upper_bound(num[i]);
    for(int i=1;i<=n;i++) fufu.lower_bound(num[i]);
    cout<<fu.get()<<'\n'<<fufu.get()<<'\n';
    return 0;
}