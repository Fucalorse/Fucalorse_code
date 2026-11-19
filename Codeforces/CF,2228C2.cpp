#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=2e5+90;

istream& operator>>(istream &in,i128 &x)
{
    string s;
    in>>s;

    x=0;
    int f=1;

    for(auto &cur:s)
    {
        if(cur=='-') f=-1;
        else x=x*10+cur-'0';
    }

    x*=f;
    return in;
}

ostream& operator<<(ostream &out,i128 x)
{
    if(x==0)
    {
        out<<0;
        return out;
    }

    if(x<0)
    {
        out<<'-';
        x=-x;
    }

    string s;
    while(x)
    {
        s.push_back(x%10+'0');
        x/=10;
    }

    reverse(s.begin(),s.end());
    out<<s;

    return out;
}

int T,n;
string a;
char d[MAX];

bool has_digit(char c)
{
    for(int i=1;i<=n;i++)
        if(d[i]==c) return true;

    return false;
}

bool valid_same_len(const string &s)
{
    int len=s.size();

    for(int i=0;i<len;i++)
    {
        if(i==0&&len>1&&s[i]=='0') return false;
        if(!has_digit(s[i])) return false;
    }

    return true;
}

i128 string_to_num(const string &s)
{
    i128 ans=0;

    for(auto &cur:s)
        ans=ans*10+cur-'0';

    return ans;
}

string cal_lower(const string &s)
{
    if(valid_same_len(s)) return s;

    int len=s.size();

    for(int i=len-1;i>=0;i--)
    {
        bool ok=true;

        for(int j=0;j<i;j++)
            if(!has_digit(s[j]))
            {
                ok=false;
                break;
            }

        if(!ok) continue;

        char best=0;
        bool found=false;

        for(int j=1;j<=n;j++)
        {
            if(d[j]<s[i])
            {
                if(i==0&&len>1&&d[j]=='0') continue;

                best=d[j];
                found=true;
            }
        }

        if(found)
        {
            string ans=s.substr(0,i);
            ans.push_back(best);

            for(int j=i+1;j<len;j++)
                ans.push_back(d[n]);

            return ans;
        }
    }

    return "";
}

string cal_greater(const string &s)
{
    if(valid_same_len(s)) return s;

    int len=s.size();

    for(int i=len-1;i>=0;i--)
    {
        bool ok=true;

        for(int j=0;j<i;j++)
            if(!has_digit(s[j]))
            {
                ok=false;
                break;
            }

        if(!ok) continue;

        char best=0;
        bool found=false;

        for(int j=n;j>=1;j--)
        {
            if(d[j]>s[i])
            {
                if(i==0&&len>1&&d[j]=='0') continue;

                best=d[j];
                found=true;
            }
        }

        if(found)
        {
            string ans=s.substr(0,i);
            ans.push_back(best);

            for(int j=i+1;j<len;j++)
                ans.push_back(d[1]);

            return ans;
        }
    }

    return "";
}

string lower_len(int len)
{
    if(len<=0) return "";

    char first=0;
    bool found=false;
    
    for(int i=n;i>=1;i--)
        if(d[i]!='0')
        {
            first=d[i];
            found=true;
            break;
        }

    if(!found) return "";

    return string(len,first);
}

string greater_len(int len)
{
    if(len<=0) return "";

    char first=0;
    bool found=false;

    for(int i=1;i<=n;i++)
        if(d[i]!='0')
        {
            first=d[i];
            found=true;
            break;
        }

    if(!found) return "";

    string ans;
    ans.push_back(first);

    for(int i=1;i<len;i++)
        ans.push_back(d[1]);

    return ans;
}

void solve()
{
    cin>>a>>n;

    for(int i=1;i<=n;i++)
        cin>>d[i];

    i128 num=string_to_num(a),ans=(i128)1<<120;
    int len=a.size();

    auto update=[&](const string &s)
    {
        if(s.empty()) return;

        i128 now=string_to_num(s);
        if(now>=num) ans=min(ans,now-num);
        else ans=min(ans,num-now);
    };

    update(cal_greater(a));
    update(cal_lower(a));
    update(lower_len(len-1));
    update(greater_len(len+1));

    if(has_digit('0')) update("0");

    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}