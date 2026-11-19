#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90;

int n,k;
int a[MAX],f[MAX];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    f[n+1]=0;
    for(int i=n;i>=1;i--)
        f[i]=max(f[i+1],a[i]);
    vector<int>rest;
    for(int i=1;i<=n;i++)
        if(f[i]==a[i]) rest.push_back(i);
    int len=n-rest.size();
    if(len>k)
    {
        vector<int>ans;
        for(int i=n,cnt=0;i>=1;i--)
        {
            if(f[i]==a[i]||cnt>=k) ans.push_back(a[i]);
            else if(cnt<k) ++cnt;
        }
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(auto &i:ans)
            cout<<i<<' ';
        cout<<endl;
    }
    else
    {
        vector<int>s1,s2;
        s1.push_back(a[rest.front()]);
        int r=k-len;
        for(size_t i=r/2+1;i<rest.size();i++)
            s1.push_back(a[rest[i]]);
        int pos;
        for(int i=1;i<=n;i++)
            if(f[i]!=a[i])
            {
                pos=i;
                break;
            }
        cout<<s1.size()<<endl;
        if(r%2==0||pos>rest.front()||s1.size()<=1)
        {
            if(s1.size()>=2&&(r&1)) swap(s1[0],s1[1]);
            for(auto &i:s1)
                cout<<i<<' ';
            cout<<endl;
            return;
        }
        s2.push_back(a[pos]);
        for(auto &i:s1)
            s2.push_back(i);
        s2.erase(s2.begin()+2);
        if(s1.size()>=2&&(r&1)) swap(s1[0],s1[1]);
        for(size_t i=0;i<s1.size()&&i<s2.size();i++)
            if(s1[i]!=s2[i])
            {
                if(s1[i]<s2[i])
                {
                    for(auto &cur:s1)
                        cout<<cur<<' ';
                    cout<<endl;
                }
                else
                {
                    for(auto &cur:s2)
                        cout<<cur<<' ';
                    cout<<endl;
                }
                break;
            }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    solve();
    return 0;
}