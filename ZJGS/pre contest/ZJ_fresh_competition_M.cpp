#include <bits/stdc++.h>
using namespace std;

const int MAX=2e5+90,inf=2e9;

int n,q;
struct fucalorse
{
    private:
        struct qwq
        {
            int cnt,lazy;
            int fl,fr;
        }op[MAX<<2];
        void create(int l,int r,int id)
        {
            op[id]={1,0,1,1};
            if(l==r) return;
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
        }
        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.cnt==inf) return b;
            if(b.cnt==inf) return a;
            qwq ans={a.cnt+b.cnt,0,a.fl,b.fr};
            if(a.fr==b.fl) ans.cnt--;
            return ans;
        }
        void down(int id)
        {
            if(op[id].lazy)
            {
                int hl=id<<1,hr=id<<1|1;
                int &k=op[id].lazy;
                op[hl]={1,k,k,k};
                op[hr]={1,k,k,k};
                op[id].lazy=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                op[id]={1,k,k,k};
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,k);
            op[id]=merge(op[hl],op[hr]);
        }
        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return {inf,inf,inf,inf};
            if(st<=l&&r<=ed) return op[id];
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &st,const int &ed,const int &k)
        {
            dfs(1,n,1,st,ed,k);
        }
        int get(const int &st,const int &ed) { return query(1,n,1,st,ed).cnt; }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    fu.debut();
    while(q--)
    {
        int p,st,ed;
        cin>>p>>st>>ed;
        if(!p)
        {
            int k;
            cin>>k;
            fu.update(st,ed,k);
        }
        else cout<<fu.get(st,ed)<<'\n';
    }
    return 0;
}