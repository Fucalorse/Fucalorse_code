#include <bits/stdc++.h>
using namespace std;

#define LL long long

namespace fucalorse
{
    struct qwq
    {
        vector<int>a;
        size_t size()const { return a.size(); }
        qwq()=default;
        explicit qwq(const string &s)
        {
            for(int i=s.size()-1;i>=0;i--)
                a.push_back(s[i]-'0');
        }
        explicit qwq(int n)
        {
            while(n)
            {
                a.push_back(n%10);
                n/=10;
            }
        }
        int &operator[](const size_t &i) { return a[i]; }
        const int &operator[](const size_t &i)const { return a[i]; }
        void push_back(const int &val) { a.push_back(val); }
        int back() { return a.back(); }
        void pop_back() { a.pop_back(); }
        void operator=(const vector<int>&b)
        {
            for(auto &i:b)
                a.push_back(i);
        }

        qwq operator+(const qwq &b)const
        {
            qwq ans;
            LL t=0;
            for(size_t i=0;i<max(a.size(),b.size());i++)
            {
                if(i<a.size()) t+=a[i];
                if(i<b.size()) t+=b[i];
                ans.push_back(t%10);
                t/=10;
            }
            while(t) ans.push_back(t%10),t/=10;
            return ans;
        }
        qwq operator+(const qwq &b)
        {
            qwq ans;
            LL t=0;
            for(size_t i=0;i<max(a.size(),b.size());i++)
            {
                if(i<a.size()) t+=a[i];
                if(i<b.size()) t+=b[i];
                ans.push_back(t%10);
                t/=10;
            }
            while(t) ans.push_back(t%10),t/=10;
            return ans;
        }
        qwq operator-(const qwq &b)
        {
            qwq ans;
            LL t=0;
            for(size_t i=0;i<a.size();i++)
            {
                t=a[i]-t;
                if(i<b.size()) t-=b[i];
                ans.push_back((t+10)%10);
                t=t<0?1:0;
            }
            while(ans.size()>1&&ans.back()==0) ans.pop_back();
            return ans;
        }
        LL operator%(const int &b)
        {
            LL t=0;
            for(int i=a.size()-1;i>=0;i--)
            {
                t=t*10+a[i];
                t%=b;
            }
            return t;
        }
        bool operator<(const qwq &b)
        {
            if(a.size()!=b.size()) return a.size()<b.size();
            for(int i=a.size()-1;i>=0;i--)
                if(a[i]!=b[i]) return a[i]<b[i];
            return false;
        }
    };
}

using namespace fucalorse;

void peach()
{
    string sn,sm;
    qwq n,M;
    int m;
    cin>>sn>>m;
    sm=to_string(m);
    for(int i=sn.size()-1;i>=0;i--)
        n.push_back(sn[i]-'0');
    for(int i=sm.size()-1;i>=0;i--)
        M.push_back(sm[i]-'0');
    if(n<M)
    {
        cout<<m<<'\n';
        return;
    }
    if(sn==sm)
    {
        qwq ans=n+n;
        for(int i=ans.size()-1;i>=0;i--)
            cout<<ans[i];
        cout<<'\n';
        return;
    }
    n=n+qwq{1};
    LL r=n%m;
    if(r==0)
    {
        for(int i=n.size()-1;i>=0;i--)
            cout<<n[i];
        cout<<'\n';
        return;
    }
    qwq R;
    while(r)
    {
        R.push_back(r%10);
        r/=10;
    }
    qwq ans=n+(M-R);
    // cout<<"21::"<<endl;
    // for(int i=ans.size()-1;i>=0;i--)
    //     cout<<ans[i];
    // cout<<endl;
    string aft="";
    for(int i=n.size()-1;i>=0;i--)
        aft+=n[i]+'0';
    if(aft.find(sm)!=string::npos) ans=n;
    n=n-qwq{1};
    for(int i=n.size()-M.size(),cnt=0;i>=0;i--)
    {
        string x=sn.substr(i,M.size());
        // cout<<x<<' ';
        if(sm>x)
        {
            string now=sn;
            // cout<<now<<' ';
            int len=i+M.size()-1;
            for(int j=i;j<=len;j++)
                now[j]=sm[j-i];
            for(int j=len+1;j<(int)n.size();j++)
                now[j]='0';
            // cout<<now<<endl;
            qwq res;
            for(int i=now.size()-1;i>=0;i--)
                res.push_back(now[i]-'0');
            if(res<ans) ans=res;
            // cout<<121<<endl;
            // for(int i=ans.size()-1;i>=0;i--)
            //     cout<<ans[i];
            // cout<<'\n';
            if(++cnt>15) break;
        }
    }
    for(int i=ans.size()-1;i>=0;i--)
        cout<<ans[i];
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--) peach();
    return 0;
}