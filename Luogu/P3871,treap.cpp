#include <bits/stdc++.h>
using namespace std;

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
    int get(qwq *pos,int k)
    {
        if(!pos) return -1;
        int num=pos->l?pos->l->size:0;
        if(k<=num) return get(pos->l,k);
        else if(num+1<=k&&k<=num+pos->cnt) return pos->val;
        else return get(pos->r,k-num-pos->cnt);
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
    void update(const int &val) { root=op.insert(root,new qwq(val)); }
    void remove(const int &val) { root=op.remove(root,val); }
    int middle()
    {
        int k=root?(root->size+1)/2:0;
        return op.get(root,k);
    }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        fu.update(a);
    }
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        string s;
        cin>>s;
        if(s[0]=='a') 
        {
            int a;
            cin>>a;
            fu.update(a);
        }
        else cout<<fu.middle()<<endl;
    }
    return 0;
}