#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;
 
struct qwq
{
    int l,r,id;
    bool operator<(const qwq &a)const { return l<a.l; }
};
set<qwq>st;
 
int t,n,m;
int a[MAX<<1],cnt[MAX<<1];

auto split(int pos)
{
    if(pos==n+1) return st.end();
    auto it=st.lower_bound({pos,0,0});
    if(it!=st.end()&&it->l==pos) return it;
    --it;
    auto [l,r,id]=*it;
    st.erase(it);
    st.insert({l,pos-1,id});
    return st.insert({pos,r,id+pos-l}).first;
}
 
struct peach
{
    private:
        struct qwq
        {
            int maxn,lazy,id;
        }op[MAX<<6];
        
        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.maxn==inf) return b;
            if(b.maxn==inf) return a;
            if(a.maxn>=b.maxn) return {a.maxn,0,a.id};
            else return {b.maxn,0,b.id};
        }
        void create(int l,int r,int id)
        {
            op[id]={0,0,0};
            if(l==r)
            {
                op[id].maxn=cnt[l];
                op[id].id=l;
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=merge(op[hl],op[hr]);
        }
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1,&k=op[id].lazy;
                op[hl].maxn+=k,op[hr].maxn+=k;
                op[hl].lazy+=k,op[hr].lazy+=k;
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id].maxn+=k;
                op[id].lazy+=k;
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id]=merge(op[hl],op[hr]);
        }
    public:
        void debut() { create(1,n*2,1); }
        void update(const int &st,const int &ed,const int &k)
        {
            dfs(1,n*2,1,st,ed,k);
        }
        pair<int,int> query() { return {op[1].id,op[1].maxn}; }
}fu;
 
void solve()
{
    cin>>n>>m;
    st.clear();
    memset(cnt,0,sizeof(int)*(n*2+10));
 
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
        st.insert({i,i,a[i]});
    }
    fu.debut();
    auto pre_val=fu.query();
    cout<<pre_val.first<<' '<<pre_val.second<<endl;
    while(m--)
    {
        int l,r,d;
        cin>>l>>r>>d;
        // printf("%d %d %d\n\n",l,r,d);
        auto itr=split(r+1);
        auto itl=split(l);
        for(auto it=itl;it!=itr;++it)
        {
            int st=it->id,ed=it->id+it->r-it->l;
            fu.update(st,ed,-1);
        }
        fu.update(d,d+r-l,1);
        st.erase(itl,itr);
        st.insert({l,r,d});
        // for(auto it=st.begin();it!=st.end();++it)
        //     cout<<it->l<<' '<<it->r<<endl;
        // cout<<endl;
        auto now=fu.query();
        cout<<now.first<<' '<<now.second<<endl;
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}