#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=60,G=3,MOD=998244353,INF=2e9;

struct peach
{
    private:
        struct qwq
        {
            array<int,2>cnt;
            bool flip;

            qwq():cnt{},flip(false){}

            qwq(const array<int,2>& _cnt,bool _flip):cnt(_cnt),flip(_flip){}

            qwq operator+(const qwq &a)const
            {
                array<int,2>ncnt;
                ncnt[0]=cnt[0]+a.cnt[0];
                ncnt[1]=cnt[1]+a.cnt[1];
                return {ncnt,false};
            }
        };

        int n;
        vector<qwq>op;

        void flip(int id)
        {
            swap(op[id].cnt[0],op[id].cnt[1]);
            op[id].flip^=1;
        }

        void down(int id)
        {
            if(op[id].flip)
            {
                int hl=id<<1,hr=id<<1|1;
                flip(hl);
                flip(hr);
                op[id].flip=false;
            }
        }

        void create(int l,int r,int id,int *a)
        {
            op[id].cnt[0]=op[id].cnt[1]=0;
            op[id].flip=false;

            if(l==r)
            {
                if(a[l]==0) op[id].cnt[0]=1;
                else op[id].cnt[1]=1;
                return;
            }
            
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl,a);
            create(mid+1,r,hr,a);

            op[id]=op[hl]+op[hr];
        }

        void dfs(int l,int r,int id,const int &st,const int &ed)
        {
            if(st<=l&&r<=ed)
            {
                flip(id);
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            if(st<=mid) dfs(l,mid,hl,st,ed);
            if(mid<ed) dfs(mid+1,r,hr,st,ed);

            op[id]=op[hl]+op[hr];
        }

        qwq query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return qwq();
            if(st<=l&&r<=ed) return op[id];

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return query(l,mid,hl,st,ed)+query(mid+1,r,hr,st,ed);
        }

        void tree(int l,int r,int id,string &s)
        {
            if(l==r)
            {
                if(op[id].cnt[0]) s.push_back('N');
                else s.push_back('H');
                return;
            }

            down(id);
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            tree(l,mid,hl,s);
            tree(mid+1,r,hr,s);
        }
    public:
        peach(int _n,int *a)
        {
            n=_n;
            op.assign((n+90)<<2,qwq());
            create(1,n,1,a);
        }

        void update_right(int pos,int stop_col)
        {
            qwq now=query(1,n,1,1,pos-1);
            int sum=now.cnt[stop_col]+1;

            int l=1,r=n,id=1;
            while(l<r)
            {
                down(id);
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                if(op[hl].cnt[stop_col]<sum)
                {
                    sum-=op[hl].cnt[stop_col];
                    l=mid+1;
                    id=hr;
                }
                else
                {
                    r=mid;
                    id=hl;
                }
            }

            dfs(1,n,1,pos,l);
        }

        void update_left(int pos,int stop_col)
        {
            qwq now=query(1,n,1,1,pos);
            int sum=now.cnt[stop_col];

            int l=1,r=n,id=1;
            while(l<r)
            {
                down(id);
                int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

                if(op[hl].cnt[stop_col]<sum)
                {
                    sum-=op[hl].cnt[stop_col];
                    l=mid+1;
                    id=hr;
                }
                else
                {
                    r=mid;
                    id=hl;
                }
            }

            dfs(1,n,1,l,pos);
        }

        string debut()
        {
            string s;
            tree(1,n,1,s);
            return s;
        }
};

int n,q;
int a[MAX];
string s;

void solve()
{
    cin>>n>>q>>s;s=' '+s;
    
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='N') a[i]=0;
        else a[i]=1;
    }

    peach fu(n,a);

    while(q--)
    {
        int opt,p;
        LL num;
        cin>>opt>>p>>num;

        int stop_col=opt&1?0:1;
        for(int k=0;k<=LEN;k++)
            if((num>>k)&1LL)
            {
                if(opt<=2)
                {
                    int pos=p+k;
                    if(pos>n) continue;
                    fu.update_right(pos,stop_col);
                }
                else
                {
                    int pos=p-k;
                    if(pos<1) continue;
                    fu.update_left(pos,stop_col);
                }
            }
    }

    cout<<fu.debut()<<endl;
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