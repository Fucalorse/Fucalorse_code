#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e6+90;

int n;
int a[MAX];

void solve()
{
    cin>>n;

    a[n+1]=0;
    vector<int>cnt(n+1,0),first(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }

    multiset<int>one,two,rest;
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==1) one.insert(i);
        else if(cnt[i]==0) two.insert(i);
    }

    for(int i=1;i<=n;i++)
        if(cnt[a[i]]==2&&first[a[i]]==-1) first[a[i]]=i;
    
    cout<<(cnt[a[1]]==2?1:0)<<endl;

    for(int l=1,r=1;l<=n;l=r)
    {
        if(first[a[l+1]]==l+1)
        {
            if(cnt[a[l]]==2&&l==1)
            {
                auto it_pre=two.begin();
                rest.insert(*it_pre);
                rest.insert(*it_pre);
                two.erase(it_pre);
            }
            else if(cnt[a[l]]==1)
            {
                auto it_pre=one.find(a[l]);
                rest.insert(*it_pre);
                one.erase(it_pre);                
            }

            r=l+1;
            while(r<=n&&first[a[r]]==r) r++;

            int interval_num=*two.begin();
            two.erase(interval_num);
            ans.push_back(interval_num);

            int len=r-l-2;
            for(int i=1;i<=len;i++)
            {
                auto it=two.begin();
                ans.push_back(*it);
                rest.insert(*it);
                two.erase(it);
            }

            ans.push_back(interval_num);
        }
        else
        {
            if(cnt[a[l]]==2)
            {
                if(l==1)
                {
                    auto it=two.begin();
                    ans.push_back(*it);
                    rest.insert(*it);
                    two.erase(it);
                }
                else
                {
                    auto it=rest.begin();
                    ans.push_back(*it);
                    rest.erase(it);
                }
                // printf("%d\n",ans.back());
                r=l+1;
                continue;
            }

            auto it=one.find(a[l]);
            ans.push_back(*it);
            one.erase(it);
            r=l+1;
        }
    }
    
    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ K.cpp -O2 -o out && ./out < in.txt