#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e6+90,LEN=26;
const int h[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

char s[MAX];

int main()
{
    cin>>s;
    int len=strlen(s);
    int ans=0;
    for(int i=0;i<LEN;i++)
    {
        int total=0;
        for(int j=0;j<len;j++)
        {
            int now=(s[j]-'A'+i)%LEN;
            total+=h[now];
        }
        ans=max(ans,total);
    }
    cout<<ans<<endl;
    return 0;
}