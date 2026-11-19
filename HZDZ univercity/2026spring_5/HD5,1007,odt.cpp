#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

struct qwq
{
    int l,r,col;
    bool operator<(const qwq &a)const { return l<a.l; }
};
set<qwq>st;

auto split(int pos)
{
    auto it=st.lower_bound({pos,0,0});
    if(it!=st.end()&&it->l==pos) return it;
    --it;
    // if(pos>it->r) return st.end();
    auto [l,r,col]=*it;
    st.erase(it);
    st.insert({l,pos-1,col});
    return st.insert({pos,r,col}).first;
}

void assign(int l,int r,int col)
{
    auto itr=split(r+1),itl=split(l);
    st.erase(itl,itr);
    st.insert({l,r,col});
}

int t,n,m,q;
int a[MAX];
LL ans[MAX];

void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
        ans[i]=0;
    st.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert({i,i,a[i]});
    }
    while(q--)
    {
        int p,l,r,x;
        cin>>p>>l>>r>>x;
        if(p==1) assign(l,r,x);
        else
        {
            auto itr=split(r+1),itl=split(l);
            for(auto it=itl;it!=itr;++it)
            {
                if(it->col==0) continue;
                int len=it->r-it->l+1;
                ans[it->col]+=(LL)len*x;
            }
        }
    }
    for(int i=1;i<=m;i++)
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