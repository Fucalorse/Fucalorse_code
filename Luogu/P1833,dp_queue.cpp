#include <bits/stdc++.h>
using namespace std;

const int MAX=1090;

int w,n;
int f[MAX];

int change()
{
    char c;
    int a,b;
    cin>>a>>c>>b;
    return a*60+b;
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
            for(int j=0;j<t;j++)
            {
                int ed=(w-j)/t;
                deque<int>id,maxn;
                for(int p=0;p<=ed;p++)
                {
                    int &now=f[j+p*t];
                    while(id.size()&&maxn.size()&&now-p*val>maxn.back())
                    {
                        maxn.pop_back();
                        id.pop_back();
                    }
                    while(id.size()&&maxn.size()&&id.front()<p-cnt)
                    {
                        id.pop_front();
                        maxn.pop_front();
                    }
                    maxn.push_back(now-p*val),id.push_back(p);
                    now=max(now,maxn.front()+p*val);
                }
            }
        }
    }
    cout<<f[w]<<'\n';
    return 0;
}