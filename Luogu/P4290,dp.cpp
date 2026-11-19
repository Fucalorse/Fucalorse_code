#include <bits/stdc++.h>
using namespace std;

const int MAX=250,LEN=7;

int cnt[LEN];
bool op[LEN][LEN][LEN],f[MAX][MAX][LEN];
unordered_map<char,int>g;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    g['W']=1,g['I']=2,g['N']=3,g['G']=4;
    for(int i=1;i<=4;i++)
        cin>>cnt[i];
    for(int i=1;i<=4;i++)
        for(int j=1;j<=cnt[i];j++)
        {
            string s;
            cin>>s;
            op[g[s[0]]][g[s[1]]][i]=true;
        }
    string s;
    cin>>s;
    int n=s.size();
    s=" "+s;
    for(int i=1;i<=n;i++)
        f[i][i][g[s[i]]]=true;
    for(int len=2;len<=n;len++)
        for(int i=1;i+len-1<=n;i++)
        {
            int st=i,ed=i+len-1;
            for(int j=st;j<ed;j++)
                for(int u=1;u<=4;u++)
                    for(int v=1;v<=4;v++)
                        for(int to=1;to<=4;to++)
                            if(f[i][j][u]&&f[j+1][ed][v]&&op[u][v][to])
                                f[i][ed][to]=true;
        }
    string ans=" WING";
    bool flag=false;
    for(int i=1;i<(int)ans.size();i++)
        if(f[1][n][i]) cout<<ans[i],flag=true;
    if(!flag) cout<<"The name is wrong!";
    cout<<'\n';
    return 0;
}