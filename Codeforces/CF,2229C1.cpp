#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

struct peach
{
    private:
        int size;
        vector<int>op;
    public:
        peach(int n) { size=n,op.assign(n+5,0); }

        void update(int n)
        {
            while(n<=size)
            {
                op[n]^=1;
                n+=n&-n;
            }
        }

        int query(int n)
        {
            int ans=0;

            while(n)
            {
                ans^=op[n];
                n-=n&-n;
            }

            return ans;
        }

        void update_range(int l,int r) { update(l),update(r+1); }
};

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>id;
    peach fu(n);
    for(int i=n;i>=1;i--)
    {
        int flip=fu.query(i);
        // cout<<flip<<' ';

        if((a[i]<0&&flip)||(a[i]>0&&!flip))
        {
            id.push_back(i);
            fu.update_range(1,i);
        }
    }
    // cout<<endl;

    cout<<id.size()<<endl;
    for(auto &cur:id)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}