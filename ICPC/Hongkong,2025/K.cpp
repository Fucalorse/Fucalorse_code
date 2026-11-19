#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

struct qwq
{
    int st_pos;
    int val,len;
    bool operator<(const qwq &a)const
    {
        if(len!=a.len) return len<a.len;
        return val>a.val;
    }
    bool operator==(const qwq &a)const { return len==a.len&&val==a.val; }
};

int n;
int a[MAX],nxt[MAX];

void solve()
{
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i+n]=a[i];
    }

    vector<int>st;
    for(int i=1;i<=n*2;i++)
    {
        while(st.size()&&a[i]>a[st.back()])
        {
            nxt[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }

    while(st.size())
    {
        nxt[st.back()]=2*n+1;
        st.pop_back();
    }

    priority_queue<qwq>q;
    for(int i=1;i<=n;i++)
        q.push({i,a[i],1});

    while(q.size())
    {
        priority_queue<qwq>nq;
        qwq minn=q.top();

        while(q.size())
        {
            if(q.top()==minn)
            {
                auto [st_pos,val,len]=q.top();q.pop();
                int nxt_pos=nxt[st_pos+len-1];
                int nxt_val=a[nxt_pos],nxt_len=nxt_pos-st_pos+1;
                if(nxt_len>n) nxt_len=2*n+1,nxt_val=n+1;
                nq.push({st_pos,nxt_val,nxt_len});
            }
            else break;
        }

        swap(q,nq);
        if(q.top().len==2*n+1) break;
    }

    int st_pos=q.top().st_pos;
    for(int round=1,i=st_pos,maxn=a[st_pos];round<=n;i++,round++)
    {
        maxn=max(maxn,a[i]);
        cout<<maxn<<' ';
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}