#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    LL val,maxn;
    int size,pri;
    qwq *l,*r;
    qwq(LL k):val(k),maxn(k),size(1),pri(dist(rng)),
    l(nullptr),r(nullptr){}
};

struct tree
{
    void maintain(qwq *pos)
    {
        if(pos)
        {
            pos->size=1,pos->maxn=pos->val;
            if(pos->l)
            {
                pos->size+=pos->l->size;
                pos->maxn=max(pos->maxn,pos->l->maxn);
            }
            if(pos->r)
            {
                pos->size+=pos->r->size;
                pos->maxn=max(pos->maxn,pos->r->maxn);
            }
        }
    }
    pair<qwq*,qwq*> split(qwq *pos,int k)
    {
        if(!pos) return {nullptr,nullptr};
        int num=pos->l?pos->l->size:0;
        if(num+1<=k)
        {
            auto [left,right]=split(pos->r,k-num-1);
            pos->r=left;
            maintain(pos);
            return {pos,right};
        }
        else
        {
            auto [left,right]=split(pos->l,k);
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
};

struct peach
{
    private:
        tree fu;
        qwq *root;
    public:
        peach() { root=nullptr; }
        void update(LL k) { root=fu.merge(root,new qwq(k)); }
        LL get_max(int len)
        {
            int cnt=root?root->size:0;
            auto [l,r]=fu.split(root,cnt-len);
            LL ans=r->maxn;
            root=fu.merge(l,r);
            return ans;
        }
}fu;

int q,mod;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>q>>mod;
    LL pre=0;
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int len;
            cin>>len;
            LL ans=fu.get_max(len);
            cout<<ans<<endl;
            pre=ans;
        }
        else
        {
            LL now;
            cin>>now;
            now=(now+pre)%mod;
            fu.update(now);
        }
    }
    return 0;
}