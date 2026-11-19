#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90;

struct qwq
{
    int l,r,col;
    bool operator<(const qwq &a)const { return l<a.l; }
};
set<qwq>st[20];

auto split(int c,int pos)
{
    auto &op=st[c];
    auto it=op.lower_bound({pos,-1,-1});
    if(it->l==pos) return it;
    --it;
    auto [l,r,col]=*it;
    op.erase(it);
    op.insert({l,pos,col});
    return op.insert({pos,r,col}).first;
}

int r,c,q;
char s[MAX][20];
int f[20][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>r>>c>>q;
    for(int i=1;i<=r;i++)
        cin>>(s[i]+1);
    int ans=0;
    for(int j=1;j<=c;j++)
    {
        for(int i=1;i<=r;i++)
        {
            f[j][i]=f[j][i-1]+(s[i][j]=='0');
            st[j].insert({i,i+1,0});
            ans+=s[i][j]=='0';
            // cout<<f[j][i]<<' ';
        }
        // cout<<endl;
    }
    // for(auto it=st[3].begin();it!=st[3].end();++it)
    //     cout<<it->l<<' '<<it->r<<' '<<it->col<<endl;
    // cout<<endl;
    while(q--)
    {
        int r1,r2,c1,c2,x;
        cin>>r1>>r2>>c1>>c2>>x;
        for(int j=c1;j<=c2;j++)
        {
            auto itr=split(j,r2+1),itl=split(j,r1);
            for(auto it=itl;it!=itr;++it)
            {
                auto &[l,r,col]=*it;
                if(col==x) continue;
                int len=r-l;
                int c0=f[j][r-1]-f[j][l-1],c1=len-c0;
                // cout<<j<<' '<<l<<' '<<r<<' '<<c0<<' '<<c1<<endl<<endl;
                if(!x) ans+=c0-c1;
                else ans+=c1-c0;
            }
            auto &op=st[j];
            op.erase(itl,itr);
            op.insert({r1,r2+1,x});
        }
        cout<<ans<<endl;
    }
    return 0;
}