#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
typedef vector<int>::iterator ovo;
const int MAX=5e5+90;

struct peach
{
    private:
        vector<LL>op;
        int size;
    public:
        peach(int n) { size=n,op.assign(n+5,0); }
        void update(int n,LL k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }
        LL query(int n)
        {
            LL ans=0;
            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }
            return ans;
        }
};

int n,m;
LL a[MAX];
vector<int>op[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    peach fu(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        fu.update(i,a[i]);
        for(int j=1;j*j<=a[i];j++)
        {
            if(a[i]%j!=0) continue;
            op[j].push_back(i);
            if(a[i]/j!=j) op[a[i]/j].push_back(i);
        }
    }
    while(m--)
    {
        int p,l,r;
        cin>>p>>l>>r;
        if(p==1)
        {
            int x;
            cin>>x;
            if(x==1||op[x].empty()) continue;
            auto &now=op[x];
            auto st=lower_bound(now.begin(),now.end(),l);
            auto ed=upper_bound(now.begin(),now.end(),r);
            if(st==now.end()) continue;
            vector<ovo>rest;
            for(auto it=st;it!=ed;++it)
            {
                if(a[*it]%x!=0) continue;
                // cout<<*it<<' '<<a[*it]<<endl;
                fu.update(*it,a[*it]/x-a[*it]);
                a[*it]/=x;
                if(a[*it]%x!=0) rest.push_back(it);
            }
            for(int i=rest.size()-1;i>=0;i--)
                now.erase(rest[i]);
        }
        else cout<<fu.query(r)-fu.query(l-1)<<endl;
    }
    return 0;
}