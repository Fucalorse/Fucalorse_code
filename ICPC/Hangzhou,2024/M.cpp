#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

int T,n;
LL k;
LL b[MAX];

void solve()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>b[i];
    
    vector<int>fa(n+1,0);
    stack<int>st;
    for(int i=1;i<=n;i++)
    {
        int last=0;

        while(st.size()&&b[st.top()]>b[i])
        {
            last=st.top();
            st.pop();
        }

        if(st.size()) fa[i]=st.top();

        if(last) fa[last]=i;

        st.push(i);
    }

    vector<pair<LL,LL>>rest;
    for(int i=1;i<=n;i++)
    {
        if(!fa[i]) continue;
        if(b[i]-b[fa[i]]) rest.push_back({b[fa[i]],b[i]-b[fa[i]]});
    }

    if(rest.empty())
    {
        cout<<k<<' '<<(1+k)*k/2<<endl;
        return;
    }

    // for(auto &[u,v]:rest)
    //     cout<<u<<' '<<v<<endl;

    auto [b0,dx]=rest.front();
    vector<LL>factor;

    auto add=[&](LL num)
    {
        LL x=num-b0;
        if(x>=1&&x<=k) factor.push_back(x);
    };

    for(LL d=1;d*d<=dx;d++)
    {
        if(dx%d!=0) continue;

        add(d);
        if(d*d!=dx) add(dx/d);
    }
    
    LL cnt=0,sum=0;
    for(auto &cur:factor)
    {
        bool ok=true;

        for(auto &[bp,dx]:rest)
        {
            LL now=bp+cur;
            if(dx%now!=0)
            {
                ok=false;
                break;
            }
        }

        if(ok) ++cnt,sum+=cur;
    }

    cout<<cnt<<' '<<sum<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();
    return 0;
}