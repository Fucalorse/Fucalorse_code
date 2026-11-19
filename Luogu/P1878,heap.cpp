#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90;

struct fucalorse
{
    private:
        struct ui
        {
            int l,r;
        }op[MAX];
    public:
        void create(int n)
        {
            for(int i=1;i<=n;i++)
                op[i]={i-1,i+1};
            op[1].l=0,op[n].r=0;
        }
        pair<int,int> pop(int i,int j)
        {
            op[op[i].l].r=op[j].r;
            op[op[j].r].l=op[i].l;
            return {op[i].l,op[j].r};
        }
}fu;

struct qwq
{
    int pa,pb,diff;
    bool operator<(const qwq &a)const 
    {
        if(diff!=a.diff) return diff>a.diff;
        return pa>a.pa;
    }
};

int n;
int num[MAX];
bool f[MAX],vis[MAX];
priority_queue<qwq>q;
vector<pair<int,int>>ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    fu.create(n);
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        if(c=='B') f[i]=true;
    }
    cin>>num[1];
    for(int i=2;i<=n;i++)
    {
        cin>>num[i];
        if(f[i]^f[i-1]) q.push({i-1,i,abs(num[i]-num[i-1])});
    }
    while(q.size())
    {
        qwq cur=q.top();q.pop();
        if(vis[cur.pa]||vis[cur.pb]) continue;
        vis[cur.pa]=vis[cur.pb]=true;
        ans.push_back({cur.pa,cur.pb});
        auto p=fu.pop(cur.pa,cur.pb);
        if(p.first&&p.second&&f[p.first]^f[p.second])
        {
            int aft=abs(num[p.first]-num[p.second]);
            q.push({p.first,p.second,aft});
        }
    }
    cout<<ans.size()<<'\n';
    for(auto now:ans)
        cout<<now.first<<' '<<now.second<<'\n';
    return 0;
}