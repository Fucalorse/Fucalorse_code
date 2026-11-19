#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int MAX=1e4+90;

struct ovo
{
    int id;
    vector<int>op;
    bool operator<(const ovo &other)const
    {
        const vector<int>&a=other.op;
        if(a.size()!=op.size()) return op.size()<a.size();
        for(size_t i=0;i<op.size()&&i<a.size();i++)
            if(op[i]!=a[i]) return op[i]<a[i];
        return false;
    }
};

struct qwq
{
    int cnt;
    vector<int>op;
    bool operator<(const qwq &other)const
    {
        if(cnt!=other.cnt) return cnt>other.cnt;
        else
        {
            const vector<int>&a=other.op;
            for(size_t i=0;i<op.size()&&i<a.size();i++)
                if(a[i]!=op[i]) return op[i]<a[i];
            return false;
        }
    }
};

bool dis(const vector<int>&a,const vector<int>&b)
{
    for(size_t i=0;i<a.size()&&i<b.size();i++)
        if(a[i]!=b[i]) return false;
    return true;
}

int n,m;
vector<ovo>num;
vector<qwq>ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        vector<int>now;
        for(int j=1;j<=m;j++)
        {
            int a;
            cin>>a;
            now.push_back(a);
        }
        num.push_back({i,now});
    }
    sort(num.begin(),num.end());
    for(size_t l=0,r=0;l<num.size();l=r)
    {
        while(r<num.size()&&dis(num[l].op,num[r].op)) r++;
        int cnt=r-l;
        ans.push_back({cnt,num[l].op});
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto &[cnt,op]:ans)
    {
        cout<<cnt;
        for(auto &i:op)
            cout<<' '<<i;
        cout<<endl;
    }
    return 0;
}