#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=26,LEN=2e5+90;

int n;
string s;
int num[LEN],ans[LEN],indeg[LEN];
vector<int>p[LEN];

struct fucalorse
{
    private:
        struct qwq
        {
            qwq *op[MAX],*fail;
            int cnt,id;
            qwq() { memset(op,0,sizeof op),fail=nullptr,cnt=0,id=0; }
        };
        qwq *root;
        int tot;

    public:
        fucalorse() { root=new qwq,tot=0; }
        void update(const string &s,const int &x)
        {
            qwq *now=root;
            for(size_t i=0;i<s.size();i++)
            {
                int p=s[i]-'a';
                if(!now->op[p]) now->op[p]=new qwq;
                now=now->op[p];
            }
            if(!now->id) now->id=x;
            num[x]=now->id;
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
                        p[cur->op[i]->id].push_back({cur->fail->op[i]->id});
                        indeg[cur->fail->op[i]->id]++;
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
                ans[now->id]++;
            }
        }
        void find()
        {
            queue<int>q;
            for(int i=1;i<=n;i++)
                if(indeg[i]==0) q.push(i);
            while(q.size())
            {
                int cur=q.front();q.pop();
                for(auto &to:p[cur])
                {
                    ans[to]+=ans[cur];
                    if(--indeg[to]==0) q.push(to);
                }
            }
        }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        fu.update(s,i);
    }
    fu.bfs();
    cin>>s;
    fu.query(s);
    // for(int i=1;i<=n;i++)
    //     cout<<ans[i]<<" ";
    fu.find();
    for(int i=1;i<=n;i++)
        cout<<ans[num[i]]<<'\n';
    return 0;
}