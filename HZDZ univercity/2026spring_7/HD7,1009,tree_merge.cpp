#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct node
{
    int id,l,r;
};

struct tree
{
    int pos;
    LL val;
}op[MAX<<2];

int t,n,m,Q;
int R[MAX];
LL V[MAX],num[MAX<<2];
vector<int>q[MAX];

struct peach
{
    private:
        void merge(int id,int l,int r)
        {
            int hl=id<<1,hr=id<<1|1;
            op[id]=op[hl];
            if(op[hl].pos>=op[hr].pos) return;
            l=((l+r)>>1)+1;
            int npos=op[hr].pos;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if(op[hr<<1].pos>op[id].pos)
                {
                    op[id].val+=op[hr].val-op[hr<<1].val;
                    hr=hr<<1;
                    r=mid;
                }
                else
                {
                    l=mid+1;
                    hr=hr<<1|1;
                }
            }
            op[id].val+=(op[hr].pos-op[id].pos)*num[hr];
            op[id].pos=npos;
        }
        void dfs(int l,int r,int id,const int &x,const int &i)
        {
            if(l==r)
            {
                op[id]={R[i],R[i]*V[i]};
                num[id]=V[i];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,i);
            else dfs(mid+1,r,hr,x,i);
            merge(id,l,r);
        }
        void find(int l,int r,int id,const int &st,const int &ed,vector<node>&rest)
        {
            if(st<=l&&r<=ed)
            {
                rest.push_back({id,l,r});
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) find(l,mid,hl,st,ed,rest);
            if(mid<ed) find(mid+1,r,hr,st,ed,rest);
        }
    public:
        void update(int x,int i) { dfs(1,m,1,x,i); }
        vector<node> split(int st,int ed)
        {
            vector<node>ans;
            find(1,m,1,st,ed,ans);
            return ans;
        }
}fu;

void clear()
{
    for(int i=1;i<=m;i++)
        q[i].clear();
}

void solve()
{
    cin>>n>>m>>Q;
    clear();
    for(int i=1;i<=m;i++)
        cin>>R[i]>>V[i];
    for(int i=1;i<=Q;i++)
    {
        int l,r;
        cin>>l>>r;
        q[r].push_back(l);
    }

    vector<int>st;
    LL ans=0;
    for(int i=1;i<=m;i++)
    {
        while(st.size()&&V[i]>=V[st.back()]) st.pop_back();
        st.push_back(i);
        fu.update((int)st.size(),i);
        for(auto &cur:q[i])
        {
            int l=lower_bound(st.begin(),st.end(),cur)-st.begin()+1;
            vector<node>rest=fu.split(l,(int)st.size());
            tree now=op[rest.front().id];
            for(size_t j=1;j<rest.size();j++)
            {
                auto [id,l,r]=rest[j];
                if(now.pos>=op[id].pos) continue;
                int npos=op[id].pos;
                while(l<r)
                {
                    int mid=(l+r)>>1;
                    if(op[id<<1].pos>now.pos)
                    {
                        now.val+=op[id].val-op[id<<1].val;
                        r=mid;
                        id=id<<1;
                    }
                    else
                    {
                        l=mid+1;
                        id=id<<1|1;
                    }
                }
                now.val+=num[id]*(op[id].pos-now.pos);
                now.pos=npos;
            }
            ans^=now.val;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}