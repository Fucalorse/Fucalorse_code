#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int T,n;
int id[MAX],reflect[MAX],pre[MAX],suf[MAX];
LL h[MAX];

void cal_l()
{
    stack<int>st;

    for(int i=n-1;i>=1;i--)
    {
        while(st.size()&&h[id[i]]>=h[id[st.top()]])
        {
            pre[st.top()]=i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size())
    {
        pre[st.top()]=0;
        st.pop();
    }
}

void cal_r()
{
    stack<int>st;

    for(int i=1;i<=n-1;i++)
    {
        while(st.size()&&h[id[i]]>h[id[st.top()]])
        {
            suf[st.top()]=i;
            st.pop();
        }

        st.push(i);
    }

    while(st.size())
    {
        suf[st.top()]=n;
        st.pop();
    }
}

void solve()
{
    cin>>n;

    int pos;
    LL maxn=0;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];

        if(h[i]>maxn)
        {
            maxn=h[i];
            pos=i;
        }
    }

    for(int st=pos%n+1,qwq=0;st!=pos;st=st%n+1)
    {
        id[++qwq]=st;
        reflect[st]=qwq;
    }
    reflect[pos]=n;
    id[n]=pos;

    cal_l(),cal_r();
    
    vector<LL>ans(n+4,0);

    auto add=[&](int l,int r,LL k)
    {
        ans[l]+=k;
        ans[r+1]-=k;
    };

    for(int i=1;i<=n-1;i++)
    {
        int l=pre[i]+1,r=suf[i];

        LL dxl=(i-l+1)*h[id[i]],dxr=(r-i)*h[id[i]];

        add(l,i,dxr);
        add(i+1,r,dxl);
    }

    for(int i=1;i<=n;i++)
        ans[i]+=ans[i-1];

    for(int i=1;i<=n;i++)
        cout<<ans[reflect[i]]<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}