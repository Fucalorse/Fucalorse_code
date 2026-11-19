#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=5e5+90;

struct discrete
{
    vector<int>num;
    void add(const int &n) { num.push_back(n); }
    void create()
    {
        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());
    }
    int find(const int &n)
    {
        return lower_bound(num.begin(),num.end(),n)-num.begin()+1;
    }
    int size() { return num.size(); }
}fu;

struct fucalorse
{
    int size;
    vector<int>op;
    fucalorse(int n)
    {
        size=n;
        op.resize(n+10,0);
    }
    int lowbit(int n) { return n&-n; }
    void update(int n)
    {
        while(n<=size)
        {
            op[n]++;
            n+=lowbit(n);
        }
    }
    int query(int n)
    {
        int ans=0;
        while(n)
        {
            ans+=op[n];
            n-=lowbit(n);
        }
        return ans;
    }
};

int n;
int num[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
        fu.add(num[i]);
    }
    fu.create();
    LL total=0;
    fucalorse fufu(fu.size());
    for(int i=n;i>=1;i--)
    {
        int x=fu.find(num[i]);
        fufu.update(x);
        total+=fufu.query(x-1);
    }
    printf("%lld\n",total);
    return 0;
}