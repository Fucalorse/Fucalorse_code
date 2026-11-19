#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ULL unsigned long long
#define LL long long
const int MAX=2e5+90,P=0x45d9f3b,Q=1e9+7;

int T,n,m;

ULL get_hash(const vector<int>& op)
{
    ULL ans=0;
    for(auto &cur:op)
        ans=ans*Q+cur;
    
    ans=((ans>>16)^ans)*P;
    ans=((ans>>16)^ans)*P;
    ans=(ans>>16)^ans;

    return ans;
}

void solve()
{
    cin>>n>>m;

    int S=0;
    vector<vector<int>>p(n+1);
    vector<bool>appear(n+1,false);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p[u].push_back(v);
        p[v].push_back(u);

        if(!appear[u])
        {
            ++S;
            appear[u]=true;
        }
        if(!appear[v])
        {
            ++S;
            appear[v]=true;
        }
    }

    map<ULL,int>mp;
    vector<vector<int>>groups;
    vector<int>rest;
    for(int i=1;i<=n;i++)
    {
        if(appear[i])
        {
            sort(p[i].begin(),p[i].end());
            ULL now=get_hash(p[i]);

            if(!mp.count(now))
            {
                mp[now]=(int)groups.size();
                groups.push_back({});
            }
            
            groups[mp[now]].push_back(i);
        }
        else rest.push_back(i);
    }

    for(int i=0;i<(int)groups.size();i++)
    {
        int cnt=groups[i].size();

        for(auto &cur:groups[i])
        {
            int now=p[cur].size();

            if(now!=S-cnt)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    if(rest.empty())
    {
        if(n==2)
        {
            cout<<"YES"<<endl;
            cout<<1<<' '<<2<<endl;
        }
        else cout<<"NO"<<endl;
    }
    else if((int)rest.size()==1)
    {
        if(S!=(int)groups.size())
        {
            cout<<"NO"<<endl;
            return;
        }

        cout<<"YES"<<endl;

        int center=rest.front();
        for(int i=1;i<=n;i++)
            if(i!=center) cout<<i<<' '<<center<<endl;
    }
    else if((int)rest.size()==2)
    {
        if((int)groups.size()!=2) cout<<"NO"<<endl;
        else
        {
            int x=rest[0],y=rest[1];

            cout<<"YES"<<endl;
            for(auto &cur:groups[0])
                cout<<x<<' '<<cur<<endl;
            for(auto &cur:groups[1])
                cout<<y<<' '<<cur<<endl;
            cout<<x<<' '<<y<<endl;
        }
    }
    else
    {
        if(rest.size()<=groups.size()) cout<<"NO"<<endl;
        else
        {
            int center=rest.front();

            cout<<"YES"<<endl;
            for(int i=1;i<=(int)groups.size();i++)
            {
                cout<<center<<' '<<rest[i]<<endl;

                for(auto &cur:groups[i-1])
                    cout<<cur<<' '<<rest[i]<<endl;
            }

            for(int i=(int)groups.size()+1;i<(int)rest.size();i++)
                cout<<rest[i]<<' '<<center<<endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}