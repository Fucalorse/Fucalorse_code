#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    int pos;
    char col;
    bool operator<(const qwq &a)const { return pos<a.pos; }
};

int n,m,k,w;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>m>>k>>w;
    
    vector<qwq>op;
    op.push_back({0,'B'}),op.push_back({w+1,'B'});
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        op.push_back({a[i],'R'});
    }

    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        op.push_back({b[i],'B'});
    }

    sort(op.begin(),op.end());

    vector<vector<int>>block;
    for(int l=0,r=0;l<(int)op.size();l=r)
    {
        if(r==(int)op.size()-1) break;

        r=l+1;
        while(r<(int)op.size()&&op[r].col!='B') r++;

        vector<int>pos;
        for(int i=l;i<=r;i++)
            pos.push_back(op[i].pos);
        if((int)pos.size()>2) block.push_back(pos);
    }

    vector<int>ans;
    for(auto &vec:block)
    {
        vector<pair<int,int>>wait;

        for(int l=1,r=1,pre=vec[0];l<(int)vec.size()-1;l=r)
        {
            while(r<(int)vec.size()-1&&vec[r]-vec[l]+1<=k) ++r;
            int st=vec[l],ed=vec[l]+k-1;
            int dx=ed-vec[r-1];

            st=max(pre+1,st-dx);
            wait.push_back({st,st+k-1});
            pre=st+k-1;
        }

        int cost=wait.back().second-vec.back()+1;
        if(cost>0)
        {
            int prer=wait.back().first,now=0,pos=-1;
            for(int i=(int)wait.size()-2;i>=0;i--)
            {
                const auto &[st,ed]=wait[i];
                now+=prer-ed-1;
                prer=st;
                if(now>=cost)
                {
                    pos=i;
                    break;
                }
            }

            if(now+wait.front().first-vec.front()-1<cost)
            {
                cout<<-1<<endl;
                return;
            }

            for(int pre=vec.back(),i=(int)wait.size()-1;i>pos;i--)
            {
                wait[i].second=pre-1;
                wait[i].first=wait[i].second-k+1;
                pre=wait[i].first;
            }
        }

        for(const auto &[st,ed]:wait)
            ans.push_back(st);
    }

    cout<<ans.size()<<endl;
    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}