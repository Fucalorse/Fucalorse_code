#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,inf=2e9;

int T,n;
int a[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    vector<int>minn(n+3,inf);
    for(int i=n;i>=1;i--)
    {
        if(a[i]<minn[i+1]) minn[i]=a[i];
        else minn[i]=minn[i+1];
    }

    LL total=0;
    int best=0;
    stack<int>st;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>minn[i+1]) total+=a[i]-minn[i+1];

        while(st.size()&&a[st.top()]>=a[i]) st.pop();

        int pre=st.size()?st.top():0;
        best=max(best,i-pre-1);

        st.push(i);
    }

    cout<<total+best<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}