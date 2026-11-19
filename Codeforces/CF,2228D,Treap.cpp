#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90,inf=2e9;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    int val,size,pri;
    qwq *l,*r;
    qwq(int k):val(k),size(1),pri(dist(rng)),
    l(nullptr),r(nullptr){}
};

struct Treap
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

    pair<qwq*,qwq*> split(qwq *pos,int k)
    {
        if(!pos) return {nullptr,nullptr};

        if(pos->val<k)
        {
            auto [left,right]=split(pos->r,k);
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

    qwq *merge(qwq *left,qwq*right)
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
            auto [left,right]=split(pos,node->val);
            node->l=left,node->r=right;
            maintain(node);

            return node;
        }

        if(node->val<pos->val) pos->l=insert(pos->l,node);
        else pos->r=insert(pos->r,node);
        maintain(pos);

        return pos;
    }

    qwq *remove(qwq *pos,int k)
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

    void clear(qwq *pos)
    {
        if(!pos) return;

        queue<qwq*>q;
        q.push(pos);

        while(q.size())
        {
            auto cur=q.front();q.pop();

            if(cur->l) q.push(cur->l);
            if(cur->r) q.push(cur->r);
            
            delete(cur);
        }
    }
};

struct peach
{
    private:
        int tot;
        qwq *root;
        Treap fu;
        vector<qwq*>pool;
    public:
        peach(int n) { root=nullptr,pool.assign(n+6,nullptr),tot=0; }
        // ~peach() { fu.clear(root); }

        void insert(int k)
        {
            pool[tot]=new qwq(k);
            root=fu.insert(root,pool[tot]);

            ++tot;
        }

        void remove(int k) { root=fu.remove(root,k); }

        int get_range_cnt(int l,int r)
        {
            auto p=fu.split(root,r+1);
            auto q=fu.split(p.first,l);

            int ans=q.second?q.second->size:0;

            root=fu.merge(q.first,q.second);
            root=fu.merge(root,p.second);

            return ans;
        }
};

struct point
{
    int x,y;
    bool operator<(const point &a)const { return x<a.x; }
}op[MAX];

int T,n;

void solve()
{
    cin>>n;

    multiset<int>right;
    vector<int>rest;
    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        cin>>op[i].x>>op[i].y;

        right.insert(op[i].y);
        rest.push_back(op[i].y);
    }

    sort(op+1,op+n+1);
    sort(rest.begin(),rest.end());
    rest.erase(unique(rest.begin(),rest.end()),rest.end());

    for(auto &cur:rest)
        fu.insert(cur);

    LL ans=0;
    int lmin=inf,lmax=-inf;
    for(int l=1,r;l<=n;l=r)
    {
        r=l;
        while(r<=n&&op[l].x==op[r].x)
        {
            auto it=right.find(op[r].y);
            assert(it!=right.end());

            right.erase(it);
            lmin=min(lmin,op[r].y);
            lmax=max(lmax,op[r].y);

            ++r;
        }

        if(right.empty()) continue;

        
        int rmin=*right.begin(),rmax=*right.rbegin();

        int low=max(lmin,rmin),high=min(lmax,rmax)-1;

        if(low<=high) ans+=fu.get_range_cnt(low,high);
    }

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}