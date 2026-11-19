#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e5+90,INF=2e9;
const LL LINF=1e18;

int n;
LL lim_time;
int p[MAX];
LL c[MAX],t[5];

void solve()
{
    cin>>n>>t[1]>>t[2]>>t[3];
    vector<LL>sum(4,0LL);
    for(int i=1;i<=n;i++)
    {
        cin>>p[i]>>c[i];
        sum[p[i]]+=c[i];
    }
    cin>>lim_time;

    vector<pair<LL,LL>>pre_vec={{t[1],sum[1]},{t[2],sum[2]},{t[3],sum[3]}};
    sort(pre_vec.begin(),pre_vec.end(),[&](const pair<LL,LL>& a,const pair<LL,LL>& b){
        return a.first<b.first;
    });

    LL total_sum=0;
    for(auto &[lim,cost]:pre_vec)
    {
        total_sum+=cost;
        if(total_sum>lim)
        {
            cout<<"NO"<<endl;
            return;
        }
    }

    LL now=0,total=0;
    vector<int>T{1,2,3};
    priority_queue<LL,vector<LL>,greater<LL>>q[4];
    sort(T.begin(),T.end(),[&](const int &i,const int &j){
        return t[i]<t[j];
    });

    for(int i=1;i<=n;i++)
        q[p[i]].push(c[i]);

    auto check=[&](pair<LL,int>cur)
    {
        auto [cost,id]=cur;
        LL n_now=now+cost;
        sum[id]-=cost;

        bool ok=true;
        LL pre_sum=0;
        for(auto &_T:T)
        {
            pre_sum+=sum[_T];
            if(sum[_T]!=0&&pre_sum+n_now>t[_T])
            {
                ok=false;
                break;
            }
        }

        sum[id]+=cost;

        return ok;
    };

    // int cnt=0;
    while(q[1].size()||q[2].size()||q[3].size())
    {
        LL c1=q[1].size()?q[1].top():LINF;
        LL c2=q[2].size()?q[2].top():LINF;
        LL c3=q[3].size()?q[3].top():LINF;
        vector<pair<LL,int>>op={{c1,1},{c2,2},{c3,3}};
        sort(op.begin(),op.end(),[&](const pair<LL,int>& a,const pair<LL,int>& b){
            return a.first<b.first;
        });

        bool ok=true;
        for(int i=0;i<3;i++)
            if(check(op[i]))
            {
                auto [cost,id]=op[i];
                now+=cost;
                total+=now;
                sum[id]-=cost;
                if(total>=lim_time)
                {
                    ok=false;
                    break;
                }

                q[id].pop();
                break;
            }

        if(!ok) break;
    }

    if(total<lim_time) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ J.cpp -O2 -o .\out.exe && .\out.exe < in.txt