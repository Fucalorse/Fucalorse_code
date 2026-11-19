#include <bits/stdc++.h>
using namespace std;

#define ULL unsigned long long
#define endl '\n'
const int MAX=1e5+90;

mt19937_64 rng(random_device{}());

int n,m,q;
int pos[MAX],cnt[MAX];
ULL num[MAX],a[MAX];
set<ULL>vis;
set<int>st;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        a[i]=rng();
        cnt[1]++;
        pos[i]=1;
        num[1]^=a[i];
    }
    st.insert(1);
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='C')
        {
            int p,to;
            cin>>p>>to;
            st.erase(pos[p]),st.erase(to);
            cnt[pos[p]]--,cnt[to]++;
            num[pos[p]]^=a[p];
            if(!vis.count(num[pos[p]])) st.insert(pos[p]);
            num[to]^=a[p];
            if(!vis.count(num[to])) st.insert(to);
            pos[p]=to;
            // for(auto it=st.begin();it!=st.end();++it)
            //     cout<<*it<<' ';
            // cout<<endl;
        }
        else
        {
            int l,r,ans=0;
            cin>>l>>r;
            auto itl=st.lower_bound(l),itr=st.upper_bound(r);
            for(auto it=itl;it!=itr;++it)
            {
                if(vis.count(num[*it])) continue;
                vis.insert(num[*it]);
                ans+=cnt[*it];
            }
            st.erase(itl,itr);
            cout<<ans<<endl;
        }
    }
    return 0;
}