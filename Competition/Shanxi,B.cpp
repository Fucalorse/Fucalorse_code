#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;
const LL inf=1e18;

int n,ops;
LL a[MAX],sum[MAX],cnt[MAX];

void solve()
{
    cin>>n>>ops;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        // cout<<sum[i]<<" ";
    }
    LL total=0,minn=inf;
    for(int i=n;i>=1;i--)
    {
        cnt[i]=sum[i]-i+cnt[i+1];
        minn=min(minn,cnt[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cnt[i]-=minn;
        total+=cnt[i];
    }
    cout<<total<<endl;

    if(ops==1)
    {
        set<int>st;
        vector<int>rest;
        for(int i=1;i<=n;i++)
            if(a[i]>1) st.insert(i);
        while(st.size())
        {
            auto it=st.begin();
            rest.push_back(*it);
            if(*it==1)
            {
                a[1]--,a[2]++;
                if(a[1]<=1) st.erase(it);
                if(a[2]>1) st.insert(2);
            }
            else if(*it==n)
            {
                a[n]--,a[n-1]++;
                if(a[n]<=1) st.erase(it);
                if(a[n-1]>1) st.insert(n-1);
            }
            else
            {
                a[*it]-=2;
                a[*it-1]++,a[*it+1]++;
                int pos=*it;
                if(a[*it]<=1) st.erase(it);
                if(a[pos-1]>1) st.insert(pos-1);
                if(a[pos+1]>1) st.insert(pos+1);
            }
        }
        reverse(rest.begin(),rest.end());
        for(auto &i:rest)
            cout<<i<<' ';
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}