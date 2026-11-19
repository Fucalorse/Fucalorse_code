#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,inf=2e9;

int t,n,m,q;
int R[MAX],V[MAX];
int f[MAX],depth[MAX],sz[MAX],son[MAX],top[MAX],id[MAX],num[MAX],pre[MAX],qwq=0;
vector<int>p[MAX];

void clear()
{
    qwq=0;
    for(int i=1;i<=m;i++)
        p[i].clear(),son[i]=0;
}

struct peach
{
    private:
        int op[MAX<<2];

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]=num[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
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
        void debut() { create(1,m,1); }
        int get(int st,int ed) { return query(1,m,1,st,ed); }
}fu;

struct fucalorse
{
    int dfs(int ch,int fa)
    {
        f[ch]=fa;
        depth[ch]=depth[fa]+1;
        sz[ch]=1;
        int maxn=-1;
        for(auto &to:p[ch])
        {
            if(to==fa) continue;
            sz[ch]+=dfs(to,ch);
            if(sz[to]>maxn) maxn=sz[to],son[ch]=to;
        }
        return sz[ch];
    }
    void find(int pos,int dfn)
    {
        id[pos]=++qwq;
        pre[qwq]=pos;
        num[qwq]=R[pos];
        top[pos]=dfn;
        if(!son[pos]) return;
        find(son[pos],dfn);
        for(auto &to:p[pos])
        {
            if(to==f[pos]||to==son[pos]) continue;
            find(to,to);
        }
    }
}fufu;

void solve()
{
    cin>>n>>m>>q;
    clear();
    stack<int>st;
    for(int i=1;i<=m;i++)
    {
        cin>>R[i]>>V[i];
        while(st.size()&&V[i]>=V[st.top()]) st.pop();
        f[i]=st.size()?st.top():0;
        st.push(i);
        if(f[i]) p[f[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
        if(!f[i])
        {
            fufu.dfs(i,0);
            fufu.find(i,i);
        }
    // for(int i=1;i<=m;i++)
    //     printf("%d ",id[i]);
    // printf("\n");
    fu.debut();
    LL ans=0;
    while(q--)
    {
        int st,ed;
        cin>>st>>ed;
        vector<int>rest;
        int cur=ed;
        while(1)
        {
            rest.push_back(cur);
            if(top[cur]>=st)
            {
                if(!f[top[cur]]||f[top[cur]]<st)
                {
                    cur=top[cur];
                    break;
                }
                cur=f[top[cur]];
            }
            else
            {
                int l=id[top[cur]],r=id[cur];
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    if(pre[mid]>=st) r=mid-1;
                    else l=mid+1;
                }
                cur=pre[l];
                break;
            }
        }
        int cur_r=R[cur];
        LL now=(LL)V[cur]*R[cur];
        reverse(rest.begin(),rest.end());
        for(auto &v:rest)
        {
            // int cnt=0;
            while(1)
            {
                // if(++cnt==10) break;
                int u=depth[cur]>depth[top[v]]?cur:top[v];
                // cout<<u<<' '<<v<<endl;
                int l=id[u],r=id[v];
                while(l<=r)
                {
                    int mid=(l+r)>>1;
                    // cout<<id[u]<<' '<<mid<<endl;
                    if(fu.get(id[u],mid)>cur_r) r=mid-1;
                    else l=mid+1;
                }
                if(l<=id[v])
                {
                    int pos=pre[l];
                    now+=(LL)V[pos]*(R[pos]-cur_r);
                    cur_r=R[pos];
                    cur=pos;
                    // cout<<cur_r<<endl;
                }
                else break;
                // printf("%d ",cur);
            }
        }
        ans^=now;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}