#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

const int MAX=1090,LEN=10;

struct qwq
{
    int t,val;
};

int w,n;
int f[MAX];

int change()
{
    char c;
    int a,b;
    cin>>a>>c>>b;
    return a*60+b;
}

vector<qwq> cal(int t,int val,int cnt)
{
    vector<qwq>ans;
    for(int k=0;k<=LEN;k++)
    {
        int p=1<<k;
        if(cnt>=p)
        {
            ans.push_back({t*p,val*p});
            cnt-=p;
        }
        else
        {
            ans.push_back({t*cnt,val*cnt});
            break;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int a=change(),b=change();
    w=b-a;
    cin>>n;
    for(int s=1;s<=n;s++)
    {
        int t,val,cnt;
        cin>>t>>val>>cnt;
        if(!cnt)
        {
            for(int i=t;i<=w;i++)
                f[i]=max(f[i],f[i-t]+val);
        }
        else
        {
            vector<qwq>now=cal(t,val,cnt);
            for(auto &i:now)
                for(int k=w;k>=i.t;k--)
                    f[k]=max(f[k],f[k-i.t]+i.val);
        }
    }
    cout<<f[w]<<'\n';
    return 0;
}