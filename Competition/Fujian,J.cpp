#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long

int t;
LL n;

LL lowbit(LL x) { return x&-x; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=0;
        vector<LL>ans;
        bitset<64>bit=n;
        while(bit.count()!=1)
        {
            ans.push_back(lowbit(n));
            n+=lowbit(n);
            bit=n;
            ++cnt;
        }
        int p=log2(n);
        if(p&1)
        {
            ans.push_back(lowbit(n));
            n+=lowbit(n);
            ++cnt;
        }
        cout<<cnt<<endl;
        for(auto &i:ans)
            cout<<i<<' ';
        cout<<endl;
    }
}