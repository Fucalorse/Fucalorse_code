#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int mod=1<<14,p=0x45d9f3b;
template <typename T>
struct HASH
{
    private:
        struct qwq
        {
            int key;
            T val;
            qwq *next;
            qwq(int k):key(k),val(),next(nullptr){}
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
        ~HASH()
        {
            for(auto i:loc)
                delete(i);
        }
        T &operator[](int n)
        {
            int now=cal(n);
            qwq *cur=num[now];
            while(cur)
            {
                if(cur->key==n) return cur->val;
                cur=cur->next;
            }
            qwq *aft=new qwq(n);
            loc.push_back(aft);
            aft->next=num[now];
            num[now]=aft;
            return aft->val;
        }
        bool count(int n)
        {
            int now=cal(n);
            qwq *cur=num[now];
            while(cur)
            {
                if(cur->key==n) return true;
                cur=cur->next;
            }
            return false;
        }
};

struct qwq
{
    LL val;
    int id;
    qwq *l,*r;
    qwq(LL k,int i,qwq *a,qwq *b):val(k),id(i),l(a),r(b){}
};

struct cmp
{
    bool operator()(const qwq *a,const qwq *b)
    {
        if(a->val!=b->val) return a->val>b->val;
        return a->id<b->id;
    }
};

int n;
vector<string>op;
priority_queue<qwq*,vector<qwq*>,cmp>q;
HASH<string>f;

void dfs(qwq *pos,string s)
{
    if(pos->id)
    {
        if(s.empty()) s="0";
        f[pos->id]=s;
        return;
    }
    dfs(pos->l,s+'0');
    dfs(pos->r,s+'1');
}

void clear(qwq *pos)
{
    if(!pos) return;
    queue<qwq*>qq;
    qq.push(pos);
    while(qq.size())
    {
        qwq *cur=qq.front();qq.pop();
        if(cur->l) qq.push(cur->l);
        if(cur->r) qq.push(cur->r);
        delete(cur);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    op.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        LL val;
        cin>>op[i]>>val;
        q.push(new qwq(val,i,nullptr,nullptr));
    }
    while(q.size()>1)
    {
        qwq *a=q.top();q.pop();
        qwq *b=q.top();q.pop();
        q.push(new qwq(a->val+b->val,0,a,b));
    }
    qwq *now=q.top();q.pop();
    dfs(now,"");
    for(int i=1;i<=n;i++)
        cout<<op[i]<<' '<<f[i]<<'\n';
    clear(now);
    return 0;
}