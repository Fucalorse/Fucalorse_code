#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=2e5,MOD=1e9+7,INF=2e9;

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

        int size() { return num.size(); }
};

int n;
int a[MAX];

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
        a[i]=dis.find(a[i]);

    int m=dis.size();
    vector<vector<pair<int,int>>>block(m+1);
    vector<int>cnt(m+1,0);

    for(int i=1;i<=n;i++)
        ++cnt[a[i]];

    for(int l=1,r=1;l<=n;l=r)
    {
        while(r<=n&&a[l]==a[r]) r++;
        block[a[l]].push_back({l,r-1});
    }

    vector<int>bad;
    vector<pair<int,int>>wait;

    auto add=[&](int l,int r)
    {
        if(l>=1&&l<=n&&r>=1&&r<=n) wait.push_back({l,r});
    };

    for(int i=1;i<=m;i++)
    {
        if((int)block[i].size()<=1) continue;

        if((int)block[i].size()>3)
        {
            cout<<"NO"<<endl;
            return;
        }

        bad.push_back(i);
        auto &op=block[i];;
        int len=(int)op.size();

        for(int i=0;i<len;i++)
        {
            add(op[i].first,op[i].second+1);
            add(op[i].second,op[i].first-1);

            for(int j=0;j<len;j++)
            {
                if(i==j) continue;

                add(op[i].first,op[j].first-1);
                add(op[i].first,op[j].second+1);
                add(op[i].second,op[j].first-1);
                add(op[i].second,op[j].second+1);
            }
        }
    }

    if((int)bad.size()>=3)
    {
        cout<<"NO"<<endl;
        return;
    }

    auto check=[&]()
    {
        for(int l=1,r=1;l<=n;l=r)
        {
            while(r<=n&&a[l]==a[r]) r++;

            if(r-l!=cnt[a[l]]) return false;
        }
        return true;
    };

    if(check())
    {
        cout<<"YES"<<endl;
        return;
    }

    // for(auto &[x,y]:wait)
    //     cout<<x<<' '<<y<<endl;

    for(auto &[x,y]:wait)
    {
        swap(a[x],a[y]);
        if(check())
        {
            cout<<"YES"<<endl;
            return;
        }
        swap(a[x],a[y]);
    }

    cout<<"NO"<<endl;
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