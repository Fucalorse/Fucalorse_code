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

struct ovo
{
    int val,size,cnt,pri;
    shared_ptr<ovo>l,r;
    ovo(int k):val(k),size(1),cnt(1),
    pri(dist(rng)),l(nullptr),r(nullptr){}
};
typedef shared_ptr<ovo> qwq;

struct tree
{
    void maintain(qwq pos)
    {
        if(pos)
        {
            pos->size=pos->cnt;
            if(pos->l) pos->size+=pos->l->size;
            if(pos->r) pos->size+=pos->r->size;
        }
    }
    pair<qwq,qwq> split(qwq pos,const int &k)
    {
        if(!pos) return {nullptr,nullptr};
        if(pos->val<k)
        {
            auto p=split(pos->r,k);
            qwq left=p.first,right=p.second;
            pos->r=left;
            maintain(pos);
            return {pos,right};
        }
        else
        {
            auto p=split(pos->l,k);
            qwq left=p.first,right=p.second;
            pos->l=right;
            maintain(pos);
            return {left,pos};
        }
    }
    qwq insert(qwq pos,qwq node)
    {
        if(!pos) return node;
        if(pos->val==node->val)
        {
            pos->size++;
            pos->cnt++;
            node.reset();
            return pos;
        }
        if(node->pri>pos->pri)
        {
            auto p=split(pos,node->val);
            qwq left=p.first,right=p.second;
            node->l=left,node->r=right;
            maintain(node);
            return node;
        }
        if(node->val<pos->val) pos->l=insert(pos->l,node);
        else pos->r=insert(pos->r,node);
        maintain(pos);
        return pos;
    }
    int get(qwq pos,int k)
    {
        if(!pos) return -1;
        int num=pos->l?pos->l->size:0;
        if(k<=num) return get(pos->l,k);
        else if(num+1<=k&&k<=num+pos->cnt) return pos->val;
        else return get(pos->r,k-num-pos->cnt);
    }
};

struct fucalorse
{
    tree op;
    qwq root;
    fucalorse() { root=nullptr; }
    void update(const int &val) { root=op.insert(root,make_shared<ovo>(val)); }
    int remove(const int &val)
    {
        int pre=root?root->size:0;
        auto p=op.split(root,val);
        p.first.reset();
        root=p.second;
        int now=root?root->size:0;
        return pre-now;
    }
    int kth(const int &val)
    {
        int now=root?root->size:0;
        if(val>now) return -1;
        return op.get(root,now-val+1);
    }
}fu;

int main()
{
    int q=read(),k=read(),now=0,del=0;
    for(int i=1;i<=q;i++)
    {
        char c;
        scanf(" %c",&c);
        int val=read();
        if(c=='I'&&val>=k) fu.update(val-now);
        else if(c=='A') now+=val;
        else if(c=='S')
        {
            now-=val;
            del+=fu.remove(k-now);
        }
        else if(c=='F')
        {
            int ans=fu.kth(val);
            printf("%d\n",ans==-1?ans:ans+now);
        }
    }
    printf("%d\n",del);
    return 0;
}