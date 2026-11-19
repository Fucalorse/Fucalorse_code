#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e4+90;

int n,m,root,qwq;
int path[MAX],f[MAX],sz[MAX],maxn[MAX],num[MAX];
bool vis[MAX],ok[MAX];
vector<pair<int,int>>p[MAX];
vector<int>op;

bool cmp(const int &x,const int &y) { return path[x]<path[y]; }

void get_root(int ch,int fa,int total)
{
    sz[ch]=1;
    maxn[ch]=0;
    for(auto &[to,val]:p[ch])
    {
        if(to==fa||vis[to]) continue;
        get_root(to,ch,total);
        sz[ch]+=sz[to];
        maxn[ch]=max(maxn[ch],sz[to]);
    }
    maxn[ch]=max(maxn[ch],total-sz[ch]);
    if(!root||maxn[ch]<maxn[root]) root=ch;
}

void get_dis(int ch,int fa,int from)
{
    op.push_back(ch);
    f[ch]=from;
    for(auto &[to,val]:p[ch])
    {
        if(to==fa||vis[to]) continue;
        path[to]=path[ch]+val;
        get_dis(to,ch,from);
    }
}

void cal(int pos)
{
    op.clear();
    op.push_back(pos);
    path[pos]=0;
    f[pos]=pos;
    for(auto &[to,val]:p[pos])
    {
        if(vis[to]) continue;
        path[to]=val;
        get_dis(to,pos,to);
    }
    sort(op.begin(),op.end(),cmp);
    for(int i=1;i<=m;i++)
    {
        if(ok[i]) continue;
        int l=0,r=op.size()-1;
        while(l<r)
        {
            int now=path[op[l]]+path[op[r]];
            if(now<num[i]) l++;
            else if(now>num[i]) r--;
            else if(f[op[l]]==f[op[r]])
            {
                if(path[op[r]]==path[op[r-1]]) r--;
                else l++;
            }
            else
            {
                ok[i]=true;
                break;
            }
        }
    }
}

void peach(int pos,int total)
{
    vis[pos]=true;
    cal(pos);
    for(auto &[to,val]:p[pos])
    {
        if(vis[to]) continue;
        root=0;
        maxn[0]=n;
        int now=sz[to]<sz[pos]?sz[to]:total-sz[pos];
        get_root(to,0,now);
        peach(root,now);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        int u,v,val;
        cin>>u>>v>>val;
        p[u].push_back({v,val});
        p[v].push_back({u,val});
    }
    for(int i=1;i<=m;i++)
        cin>>num[i];
    maxn[0]=n;
    get_root(1,0,n);
    peach(root,n);
    for(int i=1;i<=m;i++)
    {
        if(ok[i]) cout<<"AYE"<<'\n';
        else cout<<"NAY"<<'\n';
    }
    return 0;
}