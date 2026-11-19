#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;

struct qwq
{
    int len;
    int minn;
    bool operator<(const qwq &a)const
    {
        if(len!=a.len) return len<a.len;
        return minn<a.minn;
    }
};

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
        cin>>b[i];

    int tot=0;
    set<qwq>st;
    vector<int>belong(n+1),minn(n+1,INF),length(n+1,0);
    vector<vector<int>>circle(1);
    vector<bool>in_circle(n+1,false);
    for(int i=1;i<=n;i++)
    {
        if(in_circle[i]) continue;

        ++tot;
        int num=INF,len=0;
        vector<int>op;
        for(int j=i;j;j=a[j])
        {
            if(in_circle[j]) break;

            ++len;
            in_circle[j]=true;
            num=min(num,a[j]);
            belong[j]=tot;
            length[tot]=len;
            op.push_back(j);
        }

        minn[tot]=num;
        st.insert({len,num});
        circle.push_back(op);
    }

    vector<bool>vis(n+1,false);
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]||b[i]==-1) continue;

        int len=length[belong[i]];
        if(len!=length[belong[b[i]]])
        {
            cout<<"NO"<<endl;
            return;
        }

        auto it=st.find({len,minn[belong[b[i]]]});
        if(it==st.end())
        {
            cout<<"NO"<<endl;
            return;
        }

        int size=circle[belong[b[i]]].size();
        for(int round=0,pos=i,num=b[i];round<size;round++,pos=a[pos],num=a[num])
        {
            ans[pos]=num;
            vis[pos]=true;
            if(b[pos]!=-1&&ans[pos]!=b[pos])
            {
                cout<<"NO"<<endl;
                return;
            }
        }

        st.erase({length[belong[b[i]]],minn[belong[b[i]]]});
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;

        auto it=st.lower_bound({length[belong[i]],-1});
        if(it==st.end())
        {
            cout<<"NO"<<endl;
            return;
        }

        for(int round=0,pos=i,num=it->minn;round<it->len;round++,pos=a[pos],num=a[num])
        {
            ans[pos]=num;
            vis[pos]=true;
        }

        st.erase(it);
    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<' ';
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