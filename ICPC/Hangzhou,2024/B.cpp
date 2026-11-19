#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define ULL unsigned long long
const int MAX=1e6+90;
const ULL FULL=(1ULL<<63)-1,inf=-1;

struct node
{
    int l,r,id;
};

struct Segment
{
    private:
        struct qwq
        {
            ULL sum_and,can;
            ULL lazy;
        };

        int size;
        vector<qwq>op;

        void add(int id,int len,ULL k)
        {
            op[id].sum_and&=k;

            if(len==1) op[id].can=FULL&(~op[id].sum_and);
            else op[id].can&=k;

            op[id].lazy&=k;
        }

        void down(int l,int r,int id)
        {
            if(op[id].lazy!=FULL)
            {
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                add(hl,mid-l+1,op[id].lazy);
                add(hr,r-mid,op[id].lazy);

                // cout<<op[hl].sum_and<<' '<<op[hr].sum_and<<endl;

                op[id].lazy=FULL;
            }
        }

        qwq merge(const qwq &a,const qwq &b)
        {
            if(a.can==inf) return b;
            if(b.can==inf) return a;

            qwq now;

            now.sum_and=a.sum_and&b.sum_and;
            now.can=(a.sum_and&b.can)|(a.can&b.sum_and);
            now.lazy=FULL;

            return now;
        }

        void create(int l,int r,int id,ULL *a)
        {
            op[id].lazy=FULL;
            
            if(l==r)
            {
                op[id].sum_and=a[l];
                op[id].can=(~a[l])&FULL;
                return;
            }

            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=merge(op[hl],op[hr]);
        }

        void revise_range(int l,int r,int id,const int &st,const int &ed,const ULL &k)
        {
            if(st<=l&&r<=ed)
            {
                add(id,r-l+1,k);
                return;
            }

            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

            if(st<=mid) revise_range(l,mid,hl,st,ed,k);
            if(mid<ed) revise_range(mid+1,r,hr,st,ed,k);

            op[id]=merge(op[hl],op[hr]);
        }

        void revise_point(int l,int r,int id,const int &x,const ULL &k)
        {
            if(l==r)
            {
                op[id].sum_and=k;
                op[id].can=(~k)&FULL;
                op[id].lazy=FULL;
                return;
            }
            
            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

            if(x<=mid) revise_point(l,mid,hl,x,k);
            else revise_point(mid+1,r,hr,x,k);

            op[id]=merge(op[hl],op[hr]);
        }

        qwq query(int l,int r,int id,const int &st,const int &ed,vector<node>& rest)
        {
            if(r<st||l>ed) return {inf,inf,inf};
            if(st<=l&&r<=ed)
            {
                rest.push_back({l,r,id});
                return op[id];
            }

            down(l,r,id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

            return merge(query(l,mid,hl,st,ed,rest),query(mid+1,r,hr,st,ed,rest));
        }
    public:
        Segment(int n) { size=n,op.assign((n+90)<<2,{0,0,0}); }

        void debut(ULL *a) { create(1,size,1,a); }

        void update_range(int st,int ed,ULL k) { revise_range(1,size,1,st,ed,k); }
        void update_point(int x,ULL k) { revise_point(1,size,1,x,k); }

        ULL get(int st,int ed)
        {
            vector<node>rest;
            qwq now=query(1,size,1,st,ed,rest);

            if(now.can==0) return now.sum_and;
            else
            {
                ULL bit=log2(now.can);

                ULL val;
                for(auto [l,r,id]:rest)
                    if((op[id].can>>bit)&1)
                    {
                        while(l<r)
                        {
                            down(l,r,id);
                            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                            if((op[hl].can>>bit)&1)
                            {
                                id=hl;
                                r=mid;
                            }
                            else
                            {
                                id=hr;
                                l=mid+1;
                            }
                        }

                        val=op[id].sum_and;
                        break;
                    }
                
                return now.sum_and|((FULL^val)&now.can);
            }
        }
};

int n,q;
ULL a[MAX];

void solve()
{
    cin>>n>>q;

    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    Segment fu(n);
    fu.debut(a);

    while(q--)
    {
        int opt;
        cin>>opt;

        if(opt==1)
        {
            int l,r;
            ULL x;
            cin>>l>>r>>x;

            fu.update_range(l,r,x);
        }
        else if(opt==2)
        {
            int s;
            ULL x;
            cin>>s>>x;

            fu.update_point(s,x);
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

    solve();

    return 0;
}