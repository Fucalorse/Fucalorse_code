#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=17,G=3,MOD=998244353,INF=2e9;

int n,timer=0;
int a[MAX],f[MAX],t[MAX],vis[MAX];
vector<vector<int>>pos(1<<(LEN+1));

vector<int> cal_l()
{
    vector<int>st,op(n+1);

    for(int i=n;i>=1;i--)
    {
        while(st.size()&&a[i]>a[st.back()])
        {
            op[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }

    while(st.size())
    {
        op[st.back()]=0;
        st.pop_back();
    }

    return op;
}

vector<int> cal_r()
{
    vector<int>st,op(n+1);

    for(int i=1;i<=n;i++)
    {
        while(st.size()&&a[i]>=a[st.back()])
        {
            op[st.back()]=i;
            st.pop_back();
        }
        st.push_back(i);
    }

    while(st.size())
    {
        op[st.back()]=n+1;
        st.pop_back();
    }

    return op;
}

void solve()
{
    cin>>n;

    vector<int>order;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]^a[i];
        order.push_back(i);
    }

    int ans=0;
    vector<int>L=cal_l(),R=cal_r();

    sort(order.begin(),order.end(),[&](const int &i,const int &j){
        if(a[i]!=a[j]) return a[i]<a[j];
        return i<j;
    });

    auto check=[&](int target)
    {
        ++timer;

        for(int i=0;i<=n;i++)
        {
            t[i]=f[i]&target;
            if(vis[t[i]]!=timer)
            {
                pos[t[i]].clear();
                vis[t[i]]=timer;
            }
            if(vis[t[i]^target]!=timer)
            {
                pos[t[i]^target].clear();
                vis[t[i]^target]=timer;
            }
            pos[t[i]].push_back(i);
        }

        for(auto &cur:order)
        {
            int l=L[cur],r=R[cur];
            if((l==cur-1&&r==cur+1)||(a[cur]&target)!=target) continue;

            if(cur-l<r-cur)
            {
                for(int i=l;i<cur;i++)
                {
                    int num=t[i]^target;
                    auto it=lower_bound(pos[num].begin(),pos[num].end(),cur+(i==cur-1));
                    if(it!=pos[num].end()&&*it<r) return true;
                }
            }
            else
            {
                for(int i=cur;i<r;i++)
                {
                    int num=t[i]^target;
                    auto it=lower_bound(pos[num].begin(),pos[num].end(),l);
                    if(it!=pos[num].end()&&*it<cur-(i==cur)) return true;
                }
            }
        }

        return false;
    };

    for(int k=LEN;k>=0;k--)
        if(check(ans|(1<<k))) ans|=1<<k;

    cout<<ans<<endl;
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