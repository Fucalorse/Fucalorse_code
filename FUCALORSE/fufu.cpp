#include <bits/stdc++.h>
using namespace std;

const int MAX=1e7+90;

const int mod=1<<17,p=0x45d9f3b;
struct HASH
{
    private:
        struct qwq
        {
            int key,val;
            qwq *nxt;
            qwq(int k):key(k),val(0),nxt(nullptr){}
        };
        qwq *num[mod];
        vector<qwq*>loc;

        int cal(int n)
        {
            n=((n>>16)^n)*p;
            n=((n>>16)^n)*p;
            n=(n>>16)^n;
            return n&(mod-1);
        }
    public:
        HASH() { memset(num,0,sizeof num); }
        ~HASH() { for(auto &i:loc) delete(i); }
        int &operator[](int n)
        {
            int now=cal(n);
            qwq *cur=num[now];
            while(cur)
            {
                if(cur->key==n) return cur->val;
                cur=cur->nxt;
            }
            qwq *new_qwq=new qwq(n);
            loc.push_back(new_qwq);
            new_qwq->nxt=num[now];
            num[now]=new_qwq;
            return new_qwq->val;
        }
        bool count(int n)
        {
            int now=cal(n);
            qwq *cur=num[now];
            while(cur)
            {
                if(cur->key==n) return true;
                cur=cur->nxt;
            }
            return false;
        }
};

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,2e9);

struct qwq
{
    int val,size,pri;
    qwq *l,*r;
    qwq(int k):val(k),size(1),
    pri(dist(rng)),l(nullptr),r(nullptr){}
};

struct fucalorse
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
    void peach_cake(qwq *pos,HASH &f)
    {
        if(!pos) return;
        peach_cake(pos->l,f);
        if(f[pos->val]==1) cout<<pos->val<<' ';
        peach_cake(pos->r,f);
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

struct peach
{
    private:
        HASH f;
        fucalorse fu;
        qwq *root;
    public:
        peach() { root=nullptr; }
        ~peach() { fu.clear(root); }
        void update(const int &val)
        {
            if(++f[val]>1) return;
            root=fu.insert(root,new qwq(val));
        }
        void applause()
        {
            fu.peach_cake(root,f);
            cout<<'\n'<<"Made by ?"<<'\n';
        }
};

int n,m;
int a[MAX],b[MAX];
peach fufu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fufu.update(a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        fufu.update(b[i]);
    }
    fufu.applause();
    return 0;
}