#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=100;

struct tree
{
    int l,r,dfn,val;
}op[MAX];

int t,n,qwq=0,root=0;
int mid[MAX],aft[MAX],pos[MAX];

int update(int pos,const int &id,const int &x)
{
    if(!pos)
    {
        op[++qwq].dfn=id;
        op[qwq].val=x;
        return qwq;
    }
    if(id<op[pos].dfn) op[pos].l=update(op[pos].l,id,x);
    else op[pos].r=update(op[pos].r,id,x);
    return pos;
}

void clear()
{
    qwq=root=0;
    memset(op,0,sizeof op);
}

bool dfs(int depth,int pos)
{
    if(!pos) return true;
    if(op[pos].val%depth!=0) return false;
    return dfs(depth+1,op[pos].l)&&dfs(depth+1,op[pos].r);
}

void solve()
{
    unordered_map<int,int>f;
    clear();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>aft[i];
    for(int i=1;i<=n;i++)
    {
        cin>>mid[i];
        f[mid[i]]=i;
    }
    for(int i=1;i<=n;i++)
        pos[i]=f[aft[i]];
    for(int i=n;i>=1;i--)
        root=update(root,pos[i],aft[i]);
    if(dfs(1,root)) cout<<1<<endl;
    else cout<<0<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}