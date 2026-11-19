#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string s;
set<char>f;
vector<int>arr,ans;

int find(const int &x)
{
    for(size_t i=0;i<arr.size();i++)
        if(x==arr[i]) return i;
    return -1;
}

int main()
{
    cin>>s;
    for(auto &c:s)
    {
        if(f.count(c)) continue;
        f.insert(c);
        arr.push_back(c-'0');
    }
    sort(arr.begin(),arr.end(),greater<int>());
    for(auto &c:s)
        ans.push_back(find(c-'0'));
    printf("int[] arr = new int[]{");
    for(size_t i=0;i<arr.size();i++)
    {
        if(i) cout<<',';
        cout<<arr[i];
    }
    printf("};\n");
    printf("int[] index = new int[]{");
    for(size_t i=0;i<ans.size();i++)
    {
        if(i) cout<<',';
        cout<<ans[i];
    }
    printf("};\n");
    return 0;
}