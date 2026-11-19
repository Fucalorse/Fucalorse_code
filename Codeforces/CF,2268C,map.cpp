#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=17,G=3,MOD=998244353,INF=2e9;

int n;
int a[MAX],f[MAX],t[MAX];

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
    map<pair<int,int>,int>mp;
    vector<int>L=cal_l(),R=cal_r();

    for(int i=1;i<=n;i++)
        mp[{L[i],R[i]}]=i;

    sort(order.begin(),order.end(),[&](const int &i,const int &j){
        if(a[i]!=a[j]) return a[i]<a[j];
        return i<j;
    });

    auto merge=[&](map<int,int>&op,map<int,int>&a,map<int,int>&b)
    {
        if(a.size()>b.size())
        {
            swap(op,a);
            swap(a,b);
        }
        else swap(op,b);

        for(auto &[val,cnt]:a)
            if(cnt) op[val]+=cnt;
    };

    auto check=[&](int target)
    {
        for(int i=0;i<=n;i++)
            t[i]=f[i]&target;

        vector<map<int,int>>op(n+1);
        for(const auto &cur:order)
        {
            int l=L[cur],r=R[cur];
            if(l==cur-1&&r==cur+1)
            {
                ++op[cur][t[l]];
                ++op[cur][t[cur]];
            }
            else
            {
                auto it_L=mp.find({l,cur});
                map<int,int>left=it_L!=mp.end()?
                move(op[it_L->second]):map<int,int>{{t[l],1}};

                auto it_R=mp.find({cur,r});
                map<int,int>right=it_R!=mp.end()?
                move(op[it_R->second]):map<int,int>{{t[r-1],1}};

                if((a[cur]&target)!=target)
                {
                    merge(op[cur],left,right);
                    continue;
                }

                if(cur-l<r-cur)
                {
                    for(int i=l;i<cur;i++)
                    {
                        if(i==cur-1)
                        {
                            int pre=t[cur];
                            --right[pre];
                            auto it=right.find(t[i]^target);
                            if(it!=right.end()&&it->second>0) return true;
                            ++right[pre];
                        }
                        else
                        {
                            auto it=right.find(t[i]^target);
                            if(it!=right.end()&&it->second>0) return true;
                        }
                    }
                }
                else
                {
                    for(int i=cur;i<r;i++)
                    {
                        if(i==cur)
                        {
                            int pre=t[cur-1];
                            --left[pre];
                            auto it=left.find(t[i]^target);
                            if(it!=left.end()&&it->second>0) return true;
                            ++left[pre];
                        }
                        else
                        {
                            auto it=left.find(t[i]^target);
                            if(it!=left.end()&&it->second>0) return true;
                        }
                    }
                }

                merge(op[cur],left,right);
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