#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,inf=2e9;

int t,n;
int a[MAX];

bool dis(const int &mid)
{
    stack<int>st;
    st.push(a[1]>=mid?1:0);
    for(int i=2;i<=n;i++)
    {
        int now=a[i]>=mid?1:0;
        if(i+1<=n&&st.top()==0&&!now)
        {
            st.pop();
            st.push(0);
            i++;
        }
        else st.push(now);
    }
    int x=0,y=0;
    while(st.size())
    {
        int cur=st.top();st.pop();
        if(cur) x++;
        else y++;
    }
    return x>=y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=inf,r=-inf;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            l=min(l,a[i]),r=max(r,a[i]);
        }
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(dis(mid)) l=mid+1;
            else r=mid-1;
        }
        cout<<r<<endl;
    }
    return 0;
}