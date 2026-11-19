#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90,MOD=1e9+7,INF=2e9;

struct discrete
{
    private:
        vector<int>num;
    public:
        void add(int n) { num.push_back(n); }

        void create()
        {
            sort(num.begin(),num.end());
            num.erase(unique(num.begin(),num.end()),num.end());
        }

        int find(int n) { return lower_bound(num.begin(),num.end(),n)-num.begin()+1; }

        int size() { return (int)num.size(); }
};

struct qwq
{
    int val,cnt;
}op[MAX];

int T,n;
int a[MAX],pos[MAX],num[MAX];

void solve()
{
    cin>>n;

    discrete dis;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dis.add(a[i]);
    }

    dis.create();

    for(int i=1;i<=n;i++)
        num[i]=dis.find(a[i]);

    int m=dis.size();
    vector<vector<pair<int,int>>>seg(m+1);
    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&num[l]==num[r]) r++;
        seg[num[l]].push_back({l,r-1});
    }

    vector<int>bad;
    for(int i=1;i<=m;i++)
    {
        if((int)seg[i].size()<=1) continue;

        if((int)seg[i].size()>3)
        {
            cout<<"NO"<<endl;
            return;
        }

        bad.push_back(i);
    }

    if((int)bad.size()>2)
    {
        cout<<"NO"<<endl;
        return;
    }

    if(bad.empty())
    {
        cout<<"YES"<<endl;
        return;
    }

    vector<int>wait;

    auto update=[&](int pos)
    {
        if(pos>=1&&pos<=n) wait.push_back(pos);
    };

    for(auto &cur:bad)
        for(auto &[l,r]:seg[cur])
        {
            update(l-1),update(l);
            update(r),update(r+1);
        }

    sort(wait.begin(),wait.end());
    wait.erase(unique(wait.begin(),wait.end()),wait.end());

    vector<int>cnt(m+1,0),minn1(m+1,INF),minn2(m+1,INF),maxn1(m+1,-INF),maxn2(m+1,-INF);
    for(int i=1;i<=n;i++)
    {
        int v=num[i];
        ++cnt[v];

        if(i<minn1[v])
        {
            minn2[v]=minn1[v];
            minn1[v]=i;
        }
        else if(i<minn2[v]) minn2[v]=i;

        if(i>maxn1[v])
        {
            maxn2[v]=maxn1[v];
            maxn1[v]=i;
        }
        else if(i>maxn2[v]) maxn2[v]=i;
    }

    auto check=[&](int val,int from,int to)
    {
        int new_min,new_max;

        if(cnt[val]==1) new_min=new_max=to;
        else
        {
            new_min=from==minn1[val]?minn2[val]:minn1[val];
            new_max=from==maxn1[val]?maxn2[val]:maxn1[val];

            new_min=min(new_min,to);
            new_max=max(new_max,to);
        }

        return new_max-new_min+1==cnt[val];
    };

    for(size_t i=0;i<wait.size();i++)
        for(size_t j=0;j<wait.size();j++)
        {
            int p=wait[i],q=wait[j];
            int x=num[p],y=num[q];

            if(x==y) continue;

            bool ok=true;
            for(auto &cur:bad)
            {
                if(x!=cur&&y!=cur)
                {
                    ok=false;
                    break;
                }
            }

            if(!ok) continue;

            if(check(x,p,q)&&check(y,q,p))
            {
                cout<<"YES"<<endl;
                return;
            }
        }
    
    cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}