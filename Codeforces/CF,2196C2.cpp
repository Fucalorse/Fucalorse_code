#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=9e18;

int n;
int pos[MAX],tot;

void ask(int k)
{
    cout<<"? "<<k<<endl<<flush;

    cin>>tot;
    for(int i=1;i<=tot;i++)
        cin>>pos[i];
}

void print(const vector<int>& op)
{
    cout<<flush;
    for(auto &cur:op)
        cout<<cur<<' ';
    cout<<endl<<flush;
}

void solve()
{
    cin>>n;

    int now=2;
    vector<int>start(n+1,0),f(n+1,1),st;
    vector<bool>has_leave(n+1,false);
    vector<pair<int,int>>ans;
    st.push_back(1),start[1]=1;

    while(1)
    {
        ask(now);
        if(tot==0) break;
        
        set<int>path;
        for(int i=1;i<=tot;i++)
            path.insert(pos[i]);
        int cur=0;
        while(st.size()&&cur<(int)st.size())
        {
            if(path.find(st[cur])==path.end()) break;
            ++cur;
        }
        while(st.size()&&(int)st.size()>cur)
        {
            if(!has_leave[st.back()])
            {
                f[st.back()]=now-start[st.back()];
                has_leave[st.back()]=true;
            }
            // cout<<endl<<st.back()<<' '<<f[st.back()]<<endl<<flush;
            st.pop_back();
        }

        if(tot>=2) ans.push_back({pos[tot-1],pos[tot]});
        if(start[pos[tot]]) now+=f[pos[tot]];
        else
        {
            st.push_back(pos[tot]);
            start[pos[tot]]=now;
            now++;
        }
    }

    // for(int i=1;i<=n;i++)
    //     cout<<i<<' '<<start[i]<<' '<<f[i]<<endl;

    cout<<"! "<<ans.size()<<endl<<flush;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl<<flush;
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