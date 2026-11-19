#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int n) { size=n,op.assign(n+10,0); }
        void update(int n,int k)
        {
            while(n<=size)
            {
                op[n]+=k;
                n+=n&-n;
            }
        }
        int query(int n)
        {
            int ans=0;
            while(n)
            {
                ans+=op[n];
                n-=n&-n;
            }
            return ans;
        }
};

struct qwq
{
    int l,r,id;
    bool operator<(const qwq &a)const { return r<a.r; }
}op[MAX];

int n,m;
int a[MAX],pre[MAX],ans[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>op[i].l>>op[i].r;
        op[i].id=i;
    }
    sort(op+1,op+m+1);
    peach fu(n);
    for(int i=1,l=1;i<=m;i++)
    {
        // cout<<l<<' '<<op[i].r<<endl;
        while(l<=op[i].r)
        {
            if(pre[a[l]]) fu.update(pre[a[l]],-1);
            fu.update(l,1);
            pre[a[l]]=l;
            l++;
            // cout<<121<<endl;
        }
        ans[op[i].id]=fu.query(op[i].r)-fu.query(op[i].l-1);
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<endl;
    return 0;
}