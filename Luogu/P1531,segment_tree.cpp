#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,inf=2e9;

int n,m;

struct peach
{
    private:
        int op[MAX<<2];

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                cin>>op[id];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=max(op[hl],op[hr]);
        }
        void dfs(int l,int r,int id,const int &x,const int &k)
        {
            if(l==r)
            {
                op[id]=max(op[id],k);
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(x<=mid) dfs(l,mid,hl,x,k);
            else dfs(mid+1,r,hr,x,k);
            op[id]=max(op[hl],op[hr]);
        }
        int query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return -inf;
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        void update(int x,int k) { dfs(1,n,1,x,k); }
        int get(int st,int ed) { return query(1,n,1,st,ed); }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    fu.debut();
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='U')
        {
            int x,k;
            cin>>x>>k;
            fu.update(x,k);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<fu.get(l,r)<<endl;
        }
    }
    return 0;
}