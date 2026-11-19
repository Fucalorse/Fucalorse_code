#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e6+90;

int t,n,m,q;
LL ans[MAX];

struct peach
{
    private:
        struct qwq
        {
            int col;
            LL lazy;
        }op[MAX<<2];

        void add(int len,int id,const LL &k)
        {
            if(op[id].col!=-1) ans[op[id].col]+=(len)*k;
            else op[id].lazy+=k;
        }
        void down(int l,int r,int id)
        {
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            int lenl=mid-l+1,lenr=r-mid;
            if(op[id].lazy)
            {
                add(lenl,hl,op[id].lazy);
                add(lenr,hr,op[id].lazy);
                op[id].lazy=0;
            }
            if(op[id].col!=-1)
            {
                op[hl].col=op[hr].col=op[id].col;
                op[id].col=-1;
            }
        }
        void tree(int l,int r,int id)
        {
            if(l==r) return;
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            down(l,r,id);
            tree(l,mid,hl);
            tree(mid+1,r,hr);
        }
        void create(int l,int r,int id)
        {
            op[id]={-1,0};
            if(l==r)
            {
                cin>>op[id].col;
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].col=op[hl].col==op[hr].col?op[hl].col:-1;
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &p,const LL &k)
        {
            if(st<=l&&r<=ed)
            {
                if(p==1) op[id].col=k;
                else add(r-l+1,id,k);
                return;
            }
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,p,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,p,k);
            op[id].col=op[hl].col==op[hr].col?op[hl].col:-1;
        }
    public:
        void debut() { create(1,n,1); }
        void update(const int &st,const int &ed,const int &p,const LL &k)
        {
            dfs(1,n,1,st,ed,p,k);
        }
        void down_tree() { tree(1,n,1); }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        memset(ans,0,sizeof(LL)*(m+5));
        fu.debut();
        while(q--)
        {
            int st,ed,p;
            LL x;
            cin>>p>>st>>ed>>x;
            fu.update(st,ed,p,x);
        }
        fu.down_tree();
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}