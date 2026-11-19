#include <bits/stdc++.h>
using namespace std;

const int MAX=26,LEN=1.2e5;

struct ovo
{
    int pos,num;
    bool operator<(const ovo &a)const
    {
        if(num!=a.num) return num>a.num;
        return pos<a.pos;
    }
}ans[LEN];

string s[LEN];

struct fucalorse
{
    private:
        struct qwq
        {
            qwq *op[MAX],*fail;
            int exist;
            qwq() { memset(op,0,sizeof op),fail=nullptr,exist=0; }
        };
        qwq *root=new qwq;
    public:
        void debut()
        {
            root=new (root) qwq;
        }
        void update(const string &s,const int &x)
        {
            qwq *now=root;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!now->op[p]) now->op[p]=new qwq;
                now=now->op[p];
            }
            now->exist=x;
        }
        void bfs()
        {
            queue<qwq*>q;
            for(int i=0;i<MAX;i++)
            {
                if(root->op[i])
                {
                    root->op[i]->fail=root;
                    q.push(root->op[i]);
                }
                else root->op[i]=root;
            }
            while(q.size())
            {
                qwq *cur=q.front();q.pop();
                for(int i=0;i<MAX;i++)
                {
                    if(cur->op[i])
                    {
                        cur->op[i]->fail=cur->fail->op[i];
                        q.push(cur->op[i]);
                    }
                    else cur->op[i]=cur->fail->op[i];
                }
            }
        }
        void query(const string &s)
        {
            qwq *now=root;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                now=now->op[p];
                for(qwq *cur=now;cur;cur=cur->fail)
                    ans[cur->exist].num++;
            }
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n;
    while(cin>>n)
    {
        if(!n) break;
        fu.debut();
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            ans[i]={i,0};
            fu.update(s[i],i);
        }
        fu.bfs();
        cin>>s[0];
        fu.query(s[0]);
        sort(ans+1,ans+n+1);
        cout<<ans[1].num<<'\n';
        cout<<s[ans[1].pos]<<'\n';
        for(int i=2;i<=n;i++)
        {
            if(ans[i].num==ans[1].num) cout<<s[ans[i].pos]<<'\n';
            else break;
        }
    }
    return 0;
}