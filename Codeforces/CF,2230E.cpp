#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9,LEN=20;

struct qwq
{
    int p,c;
    bool operator<(const qwq &a)const
    {
        if(p!=a.p) return p<a.p;
        return c<a.c;
    }
}op[MAX],pre[MAX];

struct peach
{
    private:
        int st[MAX][LEN+3];
    public:
        void create(int n)
        {
            for(int i=1;i<=n;i++)
                st[i][0]=op[i].c+op[i].p;
            
            for(int k=1;k<=LEN;k++)
                for(int i=1;i+(1<<k)-1<=n;i++)
                    st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }

        int query(int l,int r)
        {
            if(l>r) return inf;

            int k=log2(r-l+1);
            return min(st[l][k],st[r-(1<<k)+1][k]);
        }
}fu;

int n,m;
int p[MAX],c[MAX],tp[MAX],tc[MAX],d[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        pre[i]={p[i],c[i]};
    }

    cin>>m;

    for(int i=1;i<=m;i++)
        cin>>tp[i];
    for(int i=1;i<=m;i++)
        cin>>tc[i];
    for(int i=1;i<=m;i++)
        cin>>d[i];

    sort(pre+1,pre+n+1);
    
    int len=0;
    for(int i=1;i<=n;i++)
        if(!len||pre[i].c<op[len].c) op[++len]=pre[i];

    fu.create(len);
    vector<int>ans(m+1,inf);
    for(int i=1;i<=m;i++)
    {
        auto find_p=[&](int x)
        {
            int l=1,r=len;

            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(op[mid].p<x) l=mid+1;
                else r=mid-1;
            }

            return l;
        };

        auto find_c=[&](int x)
        {
            int l=1,r=len;

            while(l<=r)
            {
                int mid=(l+r)>>1;
                if(op[mid].c>=x) l=mid+1;
                else r=mid-1;
            }

            return l;
        };

        int A=find_p(tp[i]),B=find_p(tp[i]+d[i]);
        int U=find_c(tc[i]+d[i]),V=find_c(tc[i]);

        auto cal=[&](int con)
        {
            if(con<tc[i]) return 0;
            else if(con<tc[i]+d[i]) return con;
            else return tc[i]+d[i];
        };

        //left  right
        if(A>=2) ans[i]=min(ans[i],cal(op[A-1].c));
        if(B<=len) ans[i]=min(ans[i],cal(op[len].c)+tp[i]+d[i]);

        //middle->next

        //[1,U-1]
        int l=max(A,1),r=min(B-1,U-1);
        if(l<=r) ans[i]=min(ans[i],op[l].p+tc[i]+d[i]);

        //[U,V-1]
        l=max(A,U),r=min(B-1,V-1);
        if(l<=r) ans[i]=min(ans[i],fu.query(l,r));

        //[V,len]
        l=max(A,V),r=min(B-1,len);
        if(l<=r) ans[i]=min(ans[i],op[l].p);
    }

    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    solve();

    return 0;
}