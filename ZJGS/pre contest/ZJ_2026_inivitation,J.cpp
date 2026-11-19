#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+90;

int n,cnt;
string s[5];
set<string>op;
unordered_map<string,bool>vis;
unordered_map<string,vector<string>>p;

void dfs(string pos)
{
    // cout<<pos<<' '<<vis[pos]<<endl;
    if(vis[pos]) return;
    // cout<<pos<<cnt<<endl;
    vis[pos]=true,++cnt;
    for(auto &to:p[pos])
        if(!vis[to]) dfs(to);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=4;j++)
            cin>>s[j];
        s[1].pop_back();
        // cout<<s[1]<<' '<<s[4]<<endl;
        op.insert(s[1]),op.insert(s[4]);
        p[s[4]].push_back(s[1]);
    }
    string root;
    for(auto &cur:op)
        if(!vis[cur])
        {
            dfs(cur);
            root=cur;
        }
    // cout<<root<<endl;
    cnt=0;
    for(auto &cur:op)
        vis[cur]=false;
    dfs(root);
    if(cnt==(int)op.size()) cout<<"possible"<<endl;
    else cout<<"impossible"<<endl;
    return 0;
}