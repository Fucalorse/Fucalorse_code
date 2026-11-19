#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2e5+90;

int t,n,k;
int a[MAX],op[MAX];

void solve()
{
    cin>>n>>k;
    set<int>st;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        st.insert(a[i]);
    }
    if((int)st.size()==n) op[0]=a[1],op[1]=a[2],op[2]=a[3];
    else
    {
        for(int i=1;i<=n;i++)
            if(st.count(i)==0)
            {
                op[0]=i;
                break;
            }
        op[2]=a[n];
        for(int i=1;i<=n;i++)
            if(i!=op[0]&&i!=op[2])
            {
                op[1]=i;
                break;
            }
    }
    for(int i=0;i<k;i++)
        cout<<op[i%3]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}