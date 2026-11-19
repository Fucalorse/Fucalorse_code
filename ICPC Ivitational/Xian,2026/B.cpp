#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define LL long long
#define endl '\n'
const int MAX=1e6+90,INF=2e9;
const LL LINF=9e18;

int n;
LL x,y;
int cnt[3][MAX];
string s;

void solve()
{
    cin>>n>>x>>y>>s;s=' '+s;

    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<=2;k++)
            cnt[k][i]=cnt[k][i-1];
        if(s[i]=='0') cnt[0][i]++;
        else if(s[i]=='1') cnt[1][i]++;
        else cnt[2][i]++;
    }

    LL loop_num=(x+y)/n,r=(x+y)%n;
    string ans=s;
    for(LL dx=r;dx>=0;dx--)
    {
        LL dy=r-dx;
        LL nx=x-dx,ny=y-dy;
        if(nx>=0&&nx<=x&&ny>=0&&ny<=y)
        {
            array<LL,2>need;
            need[0]=x-nx;
            need[1]=y-ny;

            if(cnt[0][r]<=need[0]&&cnt[1][r]<=need[1])
            {
                if(loop_num!=0)
                {
                    if(nx%loop_num!=0||ny%loop_num!=0) continue;
                    LL total_0=nx/loop_num,total_1=ny/loop_num;
                    if(total_0<need[0]||total_1<need[1]) continue;

                    LL suf_need0=total_0-need[0],suf_need1=total_1-need[1];
                    if(suf_need0<cnt[0][n]-cnt[0][r]||suf_need1<cnt[1][n]-cnt[1][r]) continue;                    
                }

                //prefix
                {
                    LL pre_need0=need[0]-cnt[0][r],pre_need1=need[1]-cnt[1][r];
                    for(int i=1;i<=r;i++)
                        if(s[i]=='2')
                        {
                            if(pre_need0)
                            {
                                ans[i]='0';
                                --pre_need0;
                            }
                            else
                            {
                                ans[i]='1';
                                --pre_need1;
                            }
                        }
                }

                //suffix
                if(loop_num==0)
                {
                    for(int i=r+1;i<=n;i++)
                        if(s[i]=='2') ans[i]='0';
                }
                else
                {
                    LL total_0=nx/loop_num,total_1=ny/loop_num;
                    LL suf_need0=total_0-need[0]-(cnt[0][n]-cnt[0][r]);
                    LL suf_need1=total_1-need[1]-(cnt[1][n]-cnt[1][r]);

                    for(int i=r+1;i<=n;i++)
                        if(s[i]=='2')
                        {
                            if(suf_need0)
                            {
                                ans[i]='0';
                                --suf_need0;
                            }
                            else
                            {
                                ans[i]='1';
                                --suf_need1;
                            }
                        }
                }

                for(int i=1;i<=n;i++)
                    cout<<ans[i];
                cout<<endl;
                return;
            }
        }
    }

    cout<<-1<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ B.cpp -O2 -o .\out.exe && .\out.exe < in.txt