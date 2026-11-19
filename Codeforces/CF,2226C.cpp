#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n;
int a[MAX];
multiset<int>st;

bool check(const int &mid)
{
    vector<int>rest;
    bool f=true;
    for(int i=mid-1;i>=0;i--)
    {
        if(st.count(i))
        {
            rest.push_back(i);
            st.erase(st.find(i));
        }
        else
        {
            auto it=st.lower_bound(2*i+1);
            if(it==st.end())
            {
                f=false;
                break;
            }
            rest.push_back(*it);
            st.erase(it);
        }
    }
    for(auto &i:rest)
        st.insert(i);
    return f;
}

void solve()
{
    cin>>n;
    st.clear();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    int l=0,r=n;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid-1;
    }
    cout<<r<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}