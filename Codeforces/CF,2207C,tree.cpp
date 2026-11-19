#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=2090;
const LL inf=1e17;

int t,n,h;
int pre[MAX],suf[MAX];
LL a[MAX],sum[MAX],sl[MAX],sr[MAX];

struct peach
{
    private:
        LL op[MAX<<2];

        void create(int l,int r,int id)
        {
            if(l==r)
            {
                op[id]=sum[l];
                return;
            }
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            create(l,mid,hl);
            create(mid+1,r,hr);
            op[id]=max(op[hl],op[hr]);
        }
        LL query(int l,int r,int id,const int &st,const int &ed)
        {
            if(r<st||l>ed) return -inf;
            if(st<=l&&r<=ed) return op[id];
            int mid=(l+r)>>1,hl=id<<1,hr=id<<1|1;
            return max(query(l,mid,hl,st,ed),query(mid+1,r,hr,st,ed));
        }
    public:
        void debut() { create(1,n,1); }
        LL get(int st,int ed)
        {
            if(st>ed) return -inf;
            return query(1,n,1,st,ed);
        }
}fu;

void cal_l()
{
    stack<int>st;
    for(int i=n;i>=1;i--)
    {
        while(st.size()&&a[i]>a[st.top()])
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
    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[i]>a[st.top()])
        {
            suf[st.top()]=i;
            st.pop();
        }
        st.push(i);
    }
    while(st.size())
    {
        suf[st.top()]=n+1;
        st.pop();
    }
}

void solve()
{
    cin>>n>>h; 
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cal_l(),cal_r();
    a[0]=a[n+1]=inf;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=a[i-1]) sl[i]=sl[i-1]+h-a[i];
        else sl[i]=sl[pre[i]]+(i-pre[i])*(h-a[i]);
    }
    sl[0]=sl[n+1]=sr[0]=sr[n+1]=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]<=a[i+1]) sr[i]=sr[i+1]+h-a[i];
        else sr[i]=sr[suf[i]]+(suf[i]-i)*(h-a[i]);
    }
    for(int i=1;i<=n;i++)
        sum[i]=sl[i]+sr[i]-(h-a[i]);
    fu.debut();
    // for(int i=1;i<=n;i++)
    //     cout<<sl[i]<<' '<<sr[i]<<' '<<sum[i]<<endl;
    LL ans=sum[1];
    for(int i=1;i<=n;i++)
    {
        LL l=fu.get(pre[i],i-1),r=fu.get(i+1,suf[i]);
        if(l==-inf||r==-inf)
        {
            LL now=(l==-inf?0:l)+(r==-inf?0:r);
            ans=max(ans,now);
        }
        else
        {
            LL now=l+r-sum[i];
            ans=max(ans,now);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--) solve();
    return 0;
}