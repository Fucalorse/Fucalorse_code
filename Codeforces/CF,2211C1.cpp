#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int T,n,k;
int a[MAX],b[MAX];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    
    map<int,int>cnta,cntb;
    for(int i=1;i<=k;i++)
    {
        bool similar=true;
        for(int j=i;j<=n;j+=k)
        {
            if(j+k<=n&&a[j]!=a[j+k])
            {
                similar=false;
                break;
            }
        }
        if(similar)
        {
            cnta[a[i]]++;
            set<int>st;
            for(int j=i;j<=n;j+=k)
                st.insert(b[j]);
            st.erase(-1);
            if((int)st.size()>=2)
            {
                cout<<"NO"<<endl;
                return;
            }
            if((int)st.size()==1) cntb[*st.begin()]++;
        }
        else
        {
            for(int j=i;j<=n;j+=k)
            {
                if(b[j]==-1) continue;
                if(b[j]!=a[j])
                {
                    cout<<"NO"<<endl;
                    return;
                }
            }
        }
    }
    
    for(auto [val,cnt]:cntb)
        if(cnt>cnta[val])
        {
            // cout<<cnt<<' '<<cnta[val]<<endl;
            cout<<"NO"<<endl;
            return;
        }
    
    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--) solve();
    return 0;
}