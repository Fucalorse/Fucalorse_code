#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+90,mod=1e8-3;

struct qwq
{
    int val,id;
    bool operator<(const qwq &a)const { return val<a.val; }
};

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
vector<qwq>a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    a.resize(n),b.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].val;
        a[i].id=i+1;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i].val;
        b[i].id=i+1;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n;i++)
        num[b[i].id]=a[i].id;
    fucalorse fu(n);
    int total=0;
    for(int i=n;i>=1;i--)
    {
        total=(total+fu.query(num[i]-1))%mod;
        fu.update(num[i]);
    }
    cout<<total<<'\n';
    return 0;
}