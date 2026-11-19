#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL unsigned long long
const int MAX=1e6+90;

struct qwq
{
    int l,r;
    LL val;
    bool operator<(const qwq &a)const { return l<a.l; }
}op[MAX];
set<qwq>st;
typedef set<qwq>::iterator ovo;

int n,m;
int Mod[MAX];
LL a[MAX],Val[MAX];

auto split(int pos)
{
    auto it=st.lower_bound({pos,0,0});
    if(it->l==pos) return it;
    --it;
    auto [l,r,val]=*it;
    st.erase(it);
    st.insert({l,pos,val});
    return st.insert({pos,r,val}).first;
}

LL cal(LL a,int p,const int &mod)
{
    LL ans=1,pre=a;
    if(Mod[pre]==mod) return Val[pre];
    while(p)
    {
        if(p&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        p>>=1;
    }
    Val[pre]=ans,Mod[pre]=mod;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert({i,i+1,a[i]});
    }
    LL ans=0;
    while(m--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        if(p==0)
        {
            LL u,v,w;
            cin>>u>>v>>w;
            ovo itr=split(r+1),itl=split(l),it;
            int tot=1,pos=0 ;
            for(it=itl;it!=itr;++it)
            {
                op[++tot]=*it;
                if(it->val>=u&&it->val<=v) op[tot].val=w;
            }
            st.erase(itl,itr);
            for(int i=1;i<=tot;i++)
                if(i==1||op[i].val!=op[i-1].val)
                {
                    if(pos) st.insert({pos,op[i-1].r,op[i-1].val});
                    pos=op[i].l;
                }
            st.insert({pos,r+1,op[tot].val});
        }
        else
        {
            int t,k;
            cin>>t>>k;
            auto itr=split(r+1),itl=split(l);
            LL now=0;
            for(auto it=itl;it!=itr;++it)
                now=(now+cal(it->val,t,k)*(it->r-it->l))%k;
            ans^=now;
            cout<<now<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}