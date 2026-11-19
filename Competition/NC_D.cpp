#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,LEN=2e5+90;

mt19937 rng(random_device{}());
uniform_int_distribution<int>dist(1,1e9);

struct edge
{
    int u,v,val;
    bool operator<(const edge &a)const { return val<a.val; }
}e1[LEN],e2[LEN];

int t,n,m1,m2;
int fa[4][MAX],v[4][MAX];

int find(int x,const int &i)
{
    if(fa[i][x]!=x) fa[i][x]=find(fa[i][x],i);
    return fa[i][x];
}

void combine(int x,int y,const int &i)
{
    if(x>y) swap(x,y);
    fa[i][x]=y;
    v[i][y]^=v[i][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n>>m1>>m2;
        for(int i=1;i<=n;i++)
        {
            fa[1][i]=fa[2][i]=i;
            v[1][i]=v[2][i]=dist(rng);
        }
        for(int i=1;i<=m1;i++)
        {
            int u,v,val;
            cin>>u>>v>>val;
            e1[i]={u,v,val};
        }
        for(int i=1;i<=m2;i++)
        {
            int u,v,val;
            cin>>u>>v>>val;
            e2[i]={u,v,val};
        }
        sort(e1+1,e1+m1+1),sort(e2+1,e2+m2+1);
        int i=1,j=1;
        bool f=true;
        while(i<=m1&&j<=m2)
        {
            int now=min(e1[i].val,e2[j].val);
            vector<int>rest;
            while(i<=m1&&e1[i].val<=now)
            {
                auto &[u,v,val]=e1[i++];
                int x=find(u,1),y=find(v,1);
                if(x==y) continue;
                combine(x,y,1);
                rest.push_back(find(x,1));
            }
            while(j<=m2&&e2[j].val<=now)
            {
                auto &[u,v,val]=e2[j++];
                int x=find(u,2),y=find(v,2);
                if(x==y) continue;
                combine(x,y,2);
                rest.push_back(find(x,2));
            }
            // cout<<i<<' '<<j<<endl;
            for(auto &u:rest)
                if(v[1][find(u,1)]!=v[2][find(u,2)])
                {
                    // cout<<v[1][find(u,1)]<<" "<<v[2][find(u,2)]<<endl;
                    f=false;
                    break;
                }
            if(!f) break;
        }
        // cout<<211<<' '<<f<<endl;
        if(!f)
        {
            cout<<"NO\n";
            continue;
        }
        while(i<=m1)
        {
            auto &[u,v,val]=e1[i++];
            if(find(u,1)!=find(v,1))
            {
                f=false;
                break;
            }
        }
        while(j<=m2)
        {
            auto &[u,v,val]=e2[j++];
            if(find(u,2)!=find(v,2))
            {
                f=false;
                break;
            }
        }
        if(!f)
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }
    return 0;
}