#include <bits/stdc++.h>
using namespace std;

#define LL long long
const int MAX=1e5+90;

int t,n,m,q;

struct peach
{
    private:
        struct qwq
        {
            LL pre,minn;
            LL p,q;
            bool reborn;
        }op[MAX<<2];
        int cnt;

        void create(int l,int r,int id)
        {
            op[id]={0,0,0,0,false};
            if(l==r)
            {
                cin>>op[id].pre;
                op[id].minn=op[id].pre;
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id].pre=op[id].minn=min(op[hl].minn,op[hr].minn);
        }
        void down(int id)
        {
            int hl=id<<1,hr=id<<1|1;
            if(op[id].reborn)
            {
                op[hl].minn=op[hl].pre;
                op[hl].p=op[hl].q=0,op[hl].reborn=true;
                op[hr].minn=op[hr].pre;
                op[hr].p=op[hr].q=0,op[hr].reborn=true;
                op[id].reborn=false;
            }
            if(op[id].p||op[id].q)
            {
                LL &p=op[id].p,&q=op[id].q;
                op[hl].minn=(op[hl].minn-p)/(1LL<<q);
                op[hl].p+=p,op[hl].q+=q;
                op[hr].minn=(op[hr].minn-p)/(1LL<<q);
                op[hr].p+=p,op[hr].q+=q;
                p=q=0;
            }
        }
        void dfs(int l,int r,int id,const int &st,const int &ed,const int &p,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                if(p==1)
                {
                    op[id].minn-=k;
                    op[id].p+=(1LL<<op[id].q)*k;
                    return;
                }
                else
                {
                    op[id].minn>>=1;
                    op[id].q++;
                }
                return;
            }
            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,p,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,p,k);
            op[id].minn=min(op[hl].minn,op[hr].minn);
        }
    public:
        void debut() { cnt=0,create(1,n,1); }
        void update(const int &st,const int &ed,const int &p,const int &k)
        {
            dfs(1,n,1,st,ed,p,k);
            if(op[1].minn<=m)
            {
                // cout<<op[1].minn<<endl;
                ++cnt;
                op[1].minn=op[1].pre;
                op[1].p=op[1].q=0,op[1].reborn=true;
            }
        }
        int applause() { return cnt; }
}fu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        fu.debut();
        while(q--)
        {
            int st,ed,p,k=0;
            cin>>p>>st>>ed;
            if(p==1) cin>>k;
            fu.update(st,ed,p,k);
        }
        cout<<fu.applause()<<'\n';
    }
    return 0;
}