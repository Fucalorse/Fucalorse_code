#include <bits/stdc++.h>
using namespace std;

#define LL long long

const int MAX=2e4;

struct cow
{
    LL v,x;
    bool operator<(const cow &a)const { return v<a.v; }
};

struct fucalorse
{
    struct tree
    {
        LL sum,cnt;
        tree operator+(const tree &a)const
        {
            return {sum+a.sum,cnt+a.cnt};
        }
    }op[MAX+90];
    int lowbit(int n) { return n&-n; }
    void update(int n,const LL &x)
    {
        while(n<=MAX)
        {
            op[n].cnt++;
            op[n].sum+=x;
            n+=lowbit(n);
        }
    }
    tree query(int n)
    {
        tree ans={0,0};
        while(n)
        {
            ans=ans+op[n];
            n-=lowbit(n);
        }
        return ans;
    }
    LL get(const cow &n)
    {
        tree a=query(MAX);
        tree b=query(n.x);
        return n.v*(a.sum-2*b.sum+n.x*(2*b.cnt-a.cnt));
    }
}fu;

int n;
vector<cow>op;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    op.resize(n);
    for(int i=0;i<n;i++)
        cin>>op[i].v>>op[i].x;
    sort(op.begin(),op.end());
    LL total=0;
    for(auto cur:op)
    {
        total+=fu.get(cur);
        fu.update(cur.x,cur.x);
    }
    cout<<total<<'\n';
    return 0;
}