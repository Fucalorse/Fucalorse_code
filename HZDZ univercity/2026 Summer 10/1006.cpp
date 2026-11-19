#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            int cnt;
            int fl,fr;
            int cover;
            bool reverse;
            qwq(int _cnt=0,int _fl=0,int _fr=0,int _cover=INF,bool _reverse=false):
            cnt(_cnt),fl(_fl),fr(_fr),cover(_cover),reverse(_reverse){}
        };

        int n;
        vector<qwq>op;

        void cover(int id,int k)
        {
            op[id].cover=k;
            op[id].fl=op[id].fr=k;
            op[id].cnt=1;

            op[id].reverse=false;
        }

        void reverse(int id)
        {
            op[id].fl^=1,op[id].fr^=1;

            if(op[id].cover!=INF) op[id].cover^=1;
            else op[id].reverse^=1;
        }

        void down(int id)
        {
            int hl=id<<1,hr=id<<1|1;

            if(op[id].cover!=INF)
            {
                cover(hl,op[id].cover);
                cover(hr,op[id].cover);
                op[id].cover=INF;
            }

            if(op[id].reverse)
            {
                reverse(hl);
                reverse(hr);
                op[id].reverse=false;
            }
        }

        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.cnt==INF) return b;
            if(b.cnt==INF) return a;

            int cnt=a.cnt+b.cnt;
            if(a.fr==b.fl) --cnt;
            return qwq(cnt,a.fl,b.fr,INF,false);
        }

        void create(int l,int r,int id,int *a)
        {
            if(l==r)
            {
                op[id].cnt=1;
                op[id].fl=op[id].fr=a[l];
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=merge(op[hl],op[hr]);
        }

        void dfs(int l,int r,int id,const int &st,const int &ed,const int &opt,const int &k)
        {
            if(st<=l&&r<=ed)
            {
                if(opt==1) cover(id,k);
                else reverse(id);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed,opt,k);
            if(mid<ed) dfs(mid+1,r,hr,st,ed,opt,k);

            op[id]=merge(op[hl],op[hr]);
        }

        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return qwq(INF,INF,INF,INF,false);
            if(st<=l&&r<=ed) return op[id];

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return merge(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        peach(int _n,int *a)
        {
            n=_n,op.assign((n+90)<<2,qwq());
            create(1,n,1,a);
        }

        void update(int st,int ed,int opt,int k) { dfs(1,n,1,st,ed,opt,k); }

        int get(int st,int ed) { return query(1,n,1,st,ed).cnt-1; }
};

int n,q;
int a[MAX];

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    peach fu(n,a);

    while(q--)
    {
        int opt;
        cin>>opt;

        if(opt==1)
        {
            int l,r,x;
            cin>>l>>r>>x;

            fu.update(l,r,opt,x);
        }
        else if(opt==2)
        {
            int l,r;
            cin>>l>>r;

            fu.update(l,r,opt,-10086);
        }
        else
        {
            int l,r;
            cin>>l>>r;

            cout<<fu.get(l,r)<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}