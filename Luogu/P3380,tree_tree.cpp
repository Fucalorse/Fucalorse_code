#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=3e5+90,LEN=2e5,MOD=1e9+7,INF=INT_MAX;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int get(int pos) { return num[pos-1]; }

        int size() { return (int)num.size(); }
};

struct peach
{
    private:
        struct qwq
        {
            int l,r;
            int cnt;
            qwq():l(0),r(0),cnt(0){}
        };

        int n,m;
        vector<qwq>op;
        vector<int>root;

        int seg_update(int pos,int l,int r,const int &x,const int &k)
        {
            if(!pos)
            {
                pos=op.size();
                op.emplace_back(qwq());
            }

            op[pos].cnt+=k;
            if(l==r) return pos;

            int mid=(l+r)>>1;
            if(x<=mid)
            {
                int child=seg_update(op[pos].l,l,mid,x,k);
                op[pos].l=child;
            }
            else
            {
                int child=seg_update(op[pos].r,mid+1,r,x,k);
                op[pos].r=child;
            }

            return pos;
        }

        int seg_query(const int &pos,const int &k)
        {
            if(!pos||k<=1) return 0;
            if(k>m) return op[pos].cnt;

            int ans=0,l=1,r=m,id=pos;

            while(l<r)
            {
                int mid=(l+r)>>1;

                if(k<=mid)
                {
                    id=op[id].l;
                    r=mid;
                }
                else
                {
                    ans+=op[op[id].l].cnt;
                    id=op[id].r;
                    l=mid+1;
                }
            }

            return ans;
        }
    public:
        peach(int _n,int _m)
        {
            n=_n,m=_m;
            op.emplace_back(qwq());
            root.assign(n+1,0);
        }

        void update(int pos,int value,int k)
        {
            for(int i=pos;i<=n;i+=i&-i)
                root[i]=seg_update(root[i],1,m,value,k);
        }

        void revise(int pos,int pre_value,int now_value)
        {
            for(int i=pos;i<=n;i+=i&-i)
            {
                root[i]=seg_update(root[i],1,m,pre_value,-1);
                root[i]=seg_update(root[i],1,m,now_value,1);
            }
        }

        int rank(int l,int r,int k)
        {
            int ans=1;
            for(int i=r;i;i-=i&-i)
                ans+=seg_query(root[i],k);
            for(int i=l-1;i;i-=i&-i)
                ans-=seg_query(root[i],k);

            return ans;
        }

        int kth(int l,int r,int k)
        {
            vector<int>left,right;
            for(int i=l-1;i;i-=i&-i)
                left.push_back(root[i]);
            for(int i=r;i;i-=i&-i)
                right.push_back(root[i]);

            int L=1,R=m;
            while(L<R)
            {
                int mid=(L+R)>>1,now=0;
                
                for(auto &pos:right)
                    now+=op[op[pos].l].cnt;
                for(auto &pos:left)
                    now-=op[op[pos].l].cnt;

                if(k<=now)
                {
                    R=mid;

                    for(auto &pos:left)
                        pos=op[pos].l;
                    for(auto &pos:right)
                        pos=op[pos].l;
                }
                else
                {
                    k-=now;
                    L=mid+1;

                    for(auto &pos:left)
                        pos=op[pos].r;
                    for(auto &pos:right)
                        pos=op[pos].r;
                }
            }

            return L;
        }

        int predecessor(int l,int r,int k)
        {
            int cnt=0;
            for(int i=r;i;i-=i&-i)
                cnt+=seg_query(root[i],k);
            for(int i=l-1;i;i-=i&-i)
                cnt-=seg_query(root[i],k);

            if(!cnt) return INF;

            return kth(l,r,cnt);
        }

        int successor(int l,int r,int k)
        {
            int cnt=0;
            for(int i=r;i;i-=i&-i)
                cnt+=seg_query(root[i],k+1);
            for(int i=l-1;i;i-=i&-i)
                cnt-=seg_query(root[i],k+1);

            if(cnt==r-l+1) return INF;

            return kth(l,r,cnt+1);
        }
};

struct Query
{
    int opt,l,r,pos,k;
}op[MAX];

int n,m;
int a[MAX];

void solve()
{
    cin>>n>>m;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }

    for(int i=1;i<=m;i++)
    {
        cin>>op[i].opt;
        if(op[i].opt!=3) cin>>op[i].l>>op[i].r>>op[i].k;
        else cin>>op[i].pos>>op[i].k;
        if(op[i].opt!=2) dis.add(op[i].k);
    }

    dis.create();
    for(int i=1;i<=n;i++)
        a[i]=dis.find(a[i]);
    for(int i=1;i<=m;i++)
        if(op[i].opt!=2) op[i].k=dis.find(op[i].k);

    peach fu(n,dis.size());
    for(int i=1;i<=n;i++)
        fu.update(i,a[i],1);

    for(int i=1;i<=m;i++)
    {
        auto [opt,l,r,pos,k]=op[i];

        if(opt==1) cout<<fu.rank(l,r,k)<<endl;
        else if(opt==2) cout<<dis.get(fu.kth(l,r,k))<<endl;
        else if(opt==3)
        {
            fu.revise(pos,a[pos],k);
            a[pos]=k;
        }
        else if(opt==4)
        {
            int now=fu.predecessor(l,r,k);
            if(now==INF) cout<<-INF<<endl;
            else cout<<dis.get(now)<<endl;
        }
        else
        {
            int now=fu.successor(l,r,k);
            if(now==INF) cout<<INF<<endl;
            else cout<<dis.get(now)<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    // cin>>T;
    while(T--) solve();

    return 0;
}