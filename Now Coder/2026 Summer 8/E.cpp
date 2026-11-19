#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,MOD=998244353,INF=2e9;

string s,p;
int root,n;
vector<int>sa,rk,height;
vector<int>depth,fa,suf_id;
vector<vector<int>>adj;

void build_sa()
{
    sa.assign(n+1,0);
    rk.assign(n+1,0);

    int m=256;
    vector<int>pre_rk(n+1,0),ord(n+1,0),cnt(max(n,m)+1,0);

    for(int i=1;i<=n;i++)
    {
        rk[i]=s[i]+1;
        cnt[rk[i]]++;
    }

    for(int i=1;i<=m;i++)
        cnt[i]+=cnt[i-1];

    for(int i=n;i>=1;i--)
        sa[cnt[rk[i]]--]=i;

    for(int k=1;;k<<=1)
    {
        int tot=0;

        for(int i=max(n-k+1,1);i<=n;i++)
            ord[++tot]=i;

        for(int i=1;i<=n;i++)
            if(sa[i]>k) ord[++tot]=sa[i]-k;

        for(int i=1;i<=n;i++)
            cnt[rk[ord[i]]]++;

        for(int i=n;i>=1;i--)
        {
            int x=ord[i];
            sa[cnt[rk[x]]--]=x;
        }

        pre_rk=rk;
        tot=1;
        rk[sa[1]]=1;

        for(int i=2;i<=n;i++)
        {
            int x=sa[i-1],y=sa[i];

            int x1=pre_rk[x],y1=pre_rk[y];
            int x2=x+k<=n?pre_rk[x+k]:0,y2=y+k<=n?pre_rk[y+k]:0;

            if(x1!=x2||y1!=y2) ++tot;

            rk[sa[i]]=tot;
        }

        if(tot==n) break;

        m=tot;
    }
}

void build_height()
{
    int tot=0;
    height.assign(n+1,0);

    for(int i=1;i<=n;i++)
    {
        int x=rk[i];

        if(x==1)
        {
            tot=0;
            continue;
        }

        int j=sa[x-1];
        while(i+tot<=n&&j+tot<=n&&s[i+tot]==s[j+tot]) ++tot;

        height[x]=tot;
        if(tot>0) --tot;
    }
}

int add(int dep,int suf)
{
    int u=depth.size();

    depth.push_back(dep);
    fa.push_back(-1);
    suf_id.push_back(suf);
    adj.emplace_back(vector<int>{});

    return u;
}

void build_tree()
{
    root=0;
    depth.assign(2*n+1,0);
    fa.assign(2*n+1,0);
    suf_id.assign(2*n+1,0);
    adj.assign(2*n+1,vector<int>{});

    vector<int>st;
    st.push_back(root);

    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
            int x=height[i];

            while(depth[st.back()]>x) st.pop_back();

            if(depth[st.back()]<x)
            {
                int pre=st.back();

                int last=adj[pre].back();
                int now=add(x,0);

                adj[pre].back()=now;
                fa[now]=pre;

                adj[now].push_back(last);
                fa[last]=now;

                st.push_back(now);
            }

            int leaf=add(n-sa[i]+1,sa[i]);
            int now=st.back();

            fa[leaf]=now;
            adj[now].push_back(leaf);
        }
    }
}

vector<int> cal()
{
    int n=s.size(),m=p.size();
    vector<int>op(m+1,0);
    

    for(int i=1,j=0;i<m;i++)
    {
        while(j&&p[i]!=p[j]) j=op[j];
        if(p[i]==p[j]) j++;
        op[i+1]=j;
    }

    vector<bool>vis(n+1,false);
    for(int i=0,j=0;i<n;i++)
    {
        while(j&&s[i]!=p[j]) j=op[j];
        if(s[i]==p[j]) j++;
        if(j==m)
        {
            vis[i-m+1]=true;
            j=op[j];
        }
    }

    int nxt=-1;
    vector<int>lim(n+1,0);
    for(int i=n-1;i>=0;i--)
    {
        if(vis[i]) nxt=i;
        if(nxt==-1) lim[i+1]=n-i;
        else lim[i+1]=nxt+m-i-1;
    }

    return lim;
}

void solve()
{
    cin>>s>>p;

    build_sa();
    build_height();
    build_tree();
    vector<int>lim=cal();


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