#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,k;
int a[MAX],b[MAX],op[MAX];

bool dis(int x,int y) { return x==y||y==-1; }

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    map<int,int>f,g;
    for(int i=1;i<=k;i++)
    {
        op[i]=a[i];
        for(int j=i+k;j<=n;j+=k)
            if(op[i]!=a[j])
            {
                op[i]=-1;
                break;
            }
        if(op[i]==-1)
        {
            for(int j=i;j<=n;j+=k)
                if(b[j]!=-1&&a[j]!=b[j])
                {
                    cout<<"NO"<<endl;
                    return;
                }
        }
        else
        {
            ++f[a[i]];
            set<int>st;
            for(int j=i;j<=n;j+=k)
                st.insert(b[j]);
            st.erase(-1);
            if((int)st.size()>=2)
            {
                cout<<"NO"<<endl;
                return;
            }
            else if(st.size()==1) ++g[*st.begin()];
        }
    }
    for(auto &[x,val]:g)
        if(val>f[x])
        {
            cout<<"NO"<<endl;
            return;
        }
    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}