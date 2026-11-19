#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;
const LL inf=1e18;

int t,n;
LL a[MAX];
string s;

LL del(vector<LL>&op)
{
    if((int)op.size()<=2) return 0;
    else return min(op[(int)op.size()-2]-op[0],*op.rbegin()-op[1]);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cin>>s;s=' '+s;
    vector<LL>r,g;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='R') r.push_back(a[i]);
        else g.push_back(a[i]);
    }
    sort(r.begin(),r.end()),sort(g.begin(),g.end());
    LL ans=min(max(del(r),g.size()?*g.rbegin()-*g.begin():0),max(del(g),r.size()?*r.rbegin()-*r.begin():0));
    int len=g.size();
    for(int i=0;i<len;i++)
    {
        vector<LL>op;

        if(i>=0) op.push_back(g[0]);
        if(i>=1) op.push_back(g[1]);
        if(i==2) op.push_back(g[2]);
        else if(i>2) op.push_back(g[i]),op.push_back(g[i-1]);

        int lenr=r.size();
        if(lenr>=1) op.push_back(r[0]);
        if(lenr>=2) op.push_back(r[1]);
        if(lenr==3) op.push_back(r[2]);
        else if(lenr>3) op.push_back(r.back()),op.push_back(r[(int)r.size()-2]);
        
        sort(op.begin(),op.end());
        LL del_r=del(op),del_g,now;
        if(len-i-1<=1) del_g=0,now=0;
        else del_g=min(*g.rbegin()-g[i+2],g[len-2]-g[i+1]),now=*g.rbegin()-g[i+1];
        ans=min({ans,max(del_r,now),max(del_g,op.size()?*op.rbegin()-*op.begin():0)});
    }
    for(int i=len-1;i>=0;i--)
    {
        vector<LL>op;

        int j=len-i-1;
        if(j>=0) op.push_back(g.back());
        if(j>=1) op.push_back(g[(int)g.size()-2]);
        if(j==2) op.push_back(g[(int)g.size()-3]);
        else if(j>2) op.push_back(g[i]),op.push_back(g[i+1]);

        int lenr=r.size();
        if(lenr>=1) op.push_back(r[0]);
        if(lenr>=2) op.push_back(r[1]);
        if(lenr==3) op.push_back(r[2]);
        else if(lenr>3) op.push_back(r.back()),op.push_back(r[(int)r.size()-2]);

        sort(op.begin(),op.end());
        LL del_r=del(op),del_g,now;
        if(i<=1) del_g=0,now=0;
        else del_g=min(g[i-1]-g[1],g[i-2]-g[0]),now=g[i-1]-g[0];
        ans=min({ans,max(del_r,now),max(del_g,op.size()?*op.rbegin()-*op.begin():0)});
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