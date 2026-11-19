#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=320;

int n,q,m;
int a[MAX],w[MAX],f[MAX],g[MAX],num[MAX],idx[MAX];
int pre1[MAX],suf1[MAX],pre2[LEN][MAX],suf2[LEN][MAX],ans[LEN][LEN];
int st[MAX],ed[MAX],id[MAX];

bool cmp(const int &i,const int &j){return a[i]<a[j];}

struct peach
{
    private:
        int op[MAX];
    public:
        void clear()
        {
            for(int i=1;i<=n;i++)
                op[i]=0;
        }
        void update(int pos,const int &k)
        {
            while(pos<=n)
            {
                op[pos]=max(op[pos],k);
                pos+=pos&-pos;
            }
        }
        int query(int pos)
        {
            int ans=0;
            while(pos)
            {
                ans=max(ans,op[pos]);
                pos-=pos&-pos;
            }
            return ans;
        }
}fu;

struct fucalorse
{
    void initial()
    {
        m=sqrt(n);
        for(int i=1;i<=n;i++) id[i]=(i-1)/m+1;
        for(int i=1;i<=n;i++)
        {
            st[id[i]]=(id[i]-1)*m+1;
            ed[id[i]]=min(id[i]*m,n);
        }
    }
    void create()
    {
        for(int i=1;i<=id[n];i++)
        {
            for(int j=st[i];j<=ed[i];j++) num[a[j]]=max(num[a[j]],f[j]);
            int maxn=0;
            for(int j=1;j<=n;j++)
            {
                maxn=max(maxn,num[j]);
                pre2[i][j]=maxn;
            }
        }
        for(int i=1;i<=n;i++) num[i]=0;
        for(int i=id[n];i>=1;i--)
        {
            for(int j=st[i];j<=ed[i];j++) num[a[j]]=max(num[a[j]],g[j]);
            int maxn=0;
            for(int j=n;j>=1;j--)
            {
                maxn=max(maxn,num[j]);
                suf2[i][j]=maxn;
            }
        }
        for(int i=1;i<=n;i++) idx[i]=i;
        for(int i=1;i<=id[n];i++)
        {
            int l=st[i],r=ed[i];
            sort(idx+l,idx+r+1,cmp);
            for(int j=i+2;j<=id[n];j++)
            {
                int maxn=ans[i-1][j];
                for(int k=l;k<=r;k++) maxn=max(maxn,f[k]+suf2[j][a[k]]);
                ans[i][j]=maxn;
            }
        }
    }
    int query(int l,int r)
    {
        l--,r++;
        if(l<1) return suf1[r];
        if(r>n) return pre1[l];
        int L=id[l],R=id[r];
        int maxn=max(ans[L-1][R+1],max(pre1[l],suf1[r]));
        for(int i=st[L];i<=l;i++) maxn=max(maxn,f[i]+suf2[R+1][a[i]]);
        for(int i=r;i<=ed[R];i++) maxn=max(maxn,g[i]+pre2[L-1][a[i]]);
        int now=0;
        for(int i=st[R],ir=ed[R],j=st[L],jr=ed[L];i<=ir;i++)
        {
            int &x=idx[i];
            if(x<r) continue;
            while(j<=jr)
            {
                int &y=idx[j];
                if(a[y]>a[x]) break;
                if(y<=l) now=max(now,f[y]);
                j++;
            }
            maxn=max(maxn,now+g[x]);
        }
        return maxn;
    }
}fufu;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>w[i];
    for(int i=1;i<=n;i++)
    {
        f[i]=fu.query(a[i])+w[i];
        fu.update(a[i],f[i]);
        pre1[i]=max(pre1[i-1],f[i]);
    }
    fu.clear();
    for(int i=n;i>=1;i--)
    {
        g[i]=fu.query(n-a[i]+1)+w[i];
        fu.update(n-a[i]+1,g[i]);
        suf1[i]=max(suf1[i+1],g[i]);
    }
    fufu.initial();
    fufu.create();
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<fufu.query(l,r)<<'\n';
    }
    return 0;
}