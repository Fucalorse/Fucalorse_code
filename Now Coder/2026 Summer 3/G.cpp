#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,INF=2e9;

// struct Seg_min_max
// {
//     private:
//         struct qwq
//         {
//             int minn,maxn;
//             int lz_min,lz_max;
//             qwq()
//             {
//                 minn=lz_min=INF;
//                 maxn=lz_max=-INF;
//             }
//         };

//         int n;
//         vector<qwq>op;

//         qwq merge(const qwq &a,const qwq &b)
//         {
//             qwq now;
//             now.maxn=max(a.maxn,b.maxn),now.minn=min(a.minn,b.minn);
//             now.lz_max=-INF,now.lz_min=INF;
//             return now;
//         }

//         void add_min(int id,int k)
//         {
//             op[id].minn=min(op[id].minn,k);
//             op[id].lz_min=min(op[id].lz_min,k);
//         }

//         void add_max(int id,int k)
//         {
//             op[id].maxn=max(op[id].maxn,k);
//             op[id].lz_max=max(op[id].lz_max,k);
//         }

//         void down(int id)
//         {
//             int hl=id<<1,hr=id<<1|1;

//             if(op[id].lz_min!=INF)
//             {
//                 add_min(hl,op[id].lz_min);
//                 add_min(hr,op[id].lz_min);
//                 op[id].lz_min=INF;
//             }

//             if(op[id].lz_max!=-INF)
//             {
//                 add_max(hl,op[id].lz_max);
//                 add_max(hr,op[id].lz_max);
//                 op[id].lz_max=-INF;
//             }
//         }

//         void dfs(int l,int r,int id,const int &st,const int &ed,const int &minn,const int &maxn)
//         {
//             if(st<=l&&r<=ed)
//             {
//                 add_min(id,minn);
//                 add_max(id,maxn);
//                 return;
//             }

//             down(id);
//             int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
//             if(st<=mid) dfs(l,mid,hl,st,ed,minn,maxn);
//             if(mid<ed) dfs(mid+1,r,hr,st,ed,minn,maxn);

//             op[id]=merge(op[hl],op[hr]);
//         }

//         qwq query(int l,int r,int id,const int &st,const int &ed)
//         {
//             if(st<=l&&r<=ed) return op[id];

//             down(id);
//             int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
//             qwq ans={};
//             if(st<=mid) merge(ans,query(l,mid,hl,st,ed));
//             if(mid<ed) merge(ans,query(mid+1,r,hr,st,ed));

//             return ans;
//         }
//     public:
//         Seg_min_max(int _n) { n=_n,op.assign((n+90)<<2,qwq{}); }

//         void update(int st,int ed,int minn,int maxn) { dfs(1,n,1,st,ed,minn,maxn); }

//         pair<int,int> get(int st,int ed)
//         {
//             qwq now=query(1,n,1,st,ed);
//             return {now.maxn,now.minn};
//         }
// };

// struct peach
// {
//     private:
//         struct qwq
//         {
//             int sum;
//             bool cover;
//             qwq()
//             {
//                 sum=0;
//                 cover=false;
//             }
//         };

//         int n;
//         vector<qwq>op;

//         void add(int id,int len)
//         {
//             op[id].sum=len;
//             op[id].cover=true;
//         }

//         void down(int l,int r,int id)
//         {
//             if(op[id].cover)
//             {
//                 int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
//                 add(hl,mid-l+1);
//                 add(hr,r-mid);
//                 op[id].cover=false;
//             }
//         }

//         void dfs(int l,int r,int id,const int &st,const int &ed)
//         {
//             if(st<=l&&r<=ed)
//             {
//                 add(id,r-l+1);
//                 return;
//             }

//             down(l,r,id);
//             int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;

//             if(st<=mid) dfs(l,mid,hl,st,ed);
//             if(mid<ed) dfs(mid+1,r,hr,st,ed);

//             op[id].sum=op[hl].sum+op[hr].sum;
//         }
//     public:
//         peach(int _n) { n=_n,op.assign((n+90)<<2,qwq{}); }

//         void update(int st,int ed) { dfs(1,n,1,st,ed); }

//         int get() { return op[1].sum; }
// };

struct qwq
{
    int x,y;
    bool operator<(const qwq &a)const
    {
        if(x!=a.x) return x<a.x;
        else return y<a.y;
    }
};

int n,m;

void solve()
{
    cin>>n>>m;

    vector<vector<int>>a(n+1,vector<int>(m+1));
    vector<vector<qwq>>num(n*m+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            num[a[i][j]].push_back({i,j});
        }

    vector<vector<LL>>f(n+3,vector<LL>(m+3,0));

    auto add=[&](int x1,int y1,int x2,int y2)
    {
        f[x1][y1]++;
        f[x2+1][y2+1]++;
        f[x1][y2+1]--;
        f[x2+1][y1]--;
    };

    for(int i=1;i<=n*m;i++)
    {
        auto &op=num[i];
        if(op.empty()) continue;

        sort(op.begin(),op.end());
        int len=(int)op.size();
        vector<int>suf(len+2,-INF);
        for(int i=len-1;i>=0;i--)
            suf[i]=max(suf[i+1],op[i].y);
        
        int pre=INF;
        for(int i=0;i<len-1;i++)
        {
            pre=min(pre,op[i].y);
            if(pre<=suf[i+1])
            {
                int x1=op[i].x,x2=op[i+1].x,y1=pre,y2=suf[i+1];
                if(x1<x2&&y1<y2) add(x1,y1,x2,y2);
            }
        }
    }

    vector<vector<int>>ans(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            f[i][j]+=f[i-1][j]+f[i][j-1]-f[i-1][j-1];
            if(f[i][j]) ans[i][j]=1;
        }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            cout<<ans[i][j];
        cout<<endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ G.cpp -o out && ./out < in.txt