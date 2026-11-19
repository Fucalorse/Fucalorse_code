#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e5+90,inf=2e9;

int n,m,k;
int a[MAX];
stack<int>st;
queue<int>q;
vector<vector<int>>ans;
vector<int>now;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        q.push(a[i]);
    }
    int pre=inf;
    while(q.size()||st.size())
    {
        int v=-1;
        // cout<<pre<<endl;
        if(st.size()&&st.top()<=pre) v=st.top(),st.pop();
        // cout<<v<<endl;
        if(v==-1&&q.size()&&q.front()<=pre) v=q.front(),q.pop();
        if(v==-1&&(int)st.size()<m&&q.size())
        {
            // cout<<q.front()<<endl;
            st.push(q.front()),q.pop();
            continue;
        }
        // cout<<v<<endl;
        // if(st.size()) cout<<st.size()<<' '<<st.top()<<endl;

        if(v!=-1)
        {
            now.push_back(v);
            pre=v;
        }
        if((int)now.size()==k||((int)st.size()==m&&v==-1)||(q.empty()&&v==-1))
        {
            ans.push_back(now);
            now.clear();
            pre=inf;
        }
    }
    if(now.size()) ans.push_back(now);
    // cout<<st.size()<<' '<<q.size()<<endl;
    for(auto &op:ans)
    {
        for(size_t i=0;i<op.size();i++)
        {
            if(i) cout<<" ";
            cout<<op[i];
        }
        cout<<endl;
    }
    return 0;
}