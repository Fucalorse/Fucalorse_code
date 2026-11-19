#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1090;

int m,n;
int a[MAX];
vector<int>ans;

void dfs(int pos)
{
    if(pos>n) return;
    dfs(pos<<1);
    dfs(pos<<1|1);
    ans.push_back(a[pos]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>m>>n;
    while(m--)
    {
        ans.clear();
        cin>>a[1];
        int num1=0,num2=0;
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            if(a[i]<a[i>>1]) num1++;
            else num2++;
        }
        if(num1==n-1) cout<<"Max Heap"<<endl;
        else if(num2==n-1) cout<<"Min Heap"<<endl;
        else cout<<"Not Heap"<<endl;
        dfs(1);
        for(size_t i=0;i<ans.size();i++)
        {
            if(i) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}