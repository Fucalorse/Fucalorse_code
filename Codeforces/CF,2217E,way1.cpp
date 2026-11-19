#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=14;

struct peach
{
    private:
        vector<int>op;
        int size;
        int query(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }
            return ans;
        }
    public:
        peach(int n) { size=n,op.assign(n+4,0); }
        void update(int n,int k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }
        int get(int x) { return query(size)-query(x); }
};

struct qwq
{
    int id,val;
    bool operator<(const qwq &a)const { return val>a.val; }
}op[MAX];
int t,n;
int a[MAX],d[MAX],ans[MAX];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op[i]={i,a[i]};
    }
    for(int i=1;i<=n;i++)
        cin>>d[i];
    sort(op+1,op+n+1);
    vector<int>id;
    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        int now=fu.get(op[i].id);
        if(now<d[op[i].id])
        {
            cout<<-1<<endl;
            return;
        }
        int cnt=0,dx=-1,m=now-d[op[i].id];
        for(size_t j=0;j<id.size();j++)
            if(id[j]>op[i].id)
            {
                if(cnt<m) ++cnt;
                else
                {
                    dx=(int)j;
                    break;
                }
                // cout<<cnt<<endl;
            }
        if(dx==-1) id.push_back(op[i].id);
        else id.insert(id.begin()+dx,op[i].id);
        fu.update(op[i].id,1);
    }
    // for(auto &i:id)
    //     cout<<i<<' ';
    // cout<<endl;
    for(size_t i=0;i<id.size();i++)
        ans[id[i]]=i+1;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}