#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e6+90,LEN=1e5+90;

struct peach
{
    private:
        int fa[MAX];
        int sz[MAX];
    public:
        peach()
        {
            for(int i=0;i<=LEN;i++)
                fa[i]=i,sz[i]=1;
        }
        int find(int x)
        {
            if(x!=fa[x]) fa[x]=find(fa[x]);
            return fa[x];
        }
        void combine(int x,int y)
        {
            int px=find(x),py=find(y);
            if(px==py) return;
            fa[px]=py;
            sz[py]+=sz[px];
        }
        int get(int x) { return sz[find(x)]; }
}fu;

int n,k,m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int pre;
        cin>>k>>pre;
        for(int j=2;j<=k;j++)
        {
            int a;
            cin>>a;
            fu.combine(pre,a);
        }
    }
    cin>>m;
    unordered_set<string>st;
    vector<string>ans;
    for(int i=1;i<=m;i++)
    {
        string s;
        cin>>s;
        int x=0;
        for(auto &c:s)
            x=x*10+c-'0';
        if(fu.get(x)==1)
        {
            if(st.count(s)) continue;
            st.insert(s);
            ans.push_back(s);
        }
    }
    for(size_t i=0;i<ans.size();i++)
    {
        if(i) cout<<' ';
        cout<<ans[i];
    }
    if(st.empty()) cout<<"No one is handsome";
    return 0;
}