#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
#define i128 __int128
const int MAX=1e6+90,LEN=32,G=3,MOD=998244353,INF=2e9;
const LL LINF=1e18;

struct qwq
{
    int row,col;
    bool operator<(const qwq &a)const { return col<a.col; }
};

int n;
int a[MAX],b[MAX];

void solve()
{
    cin>>n;

    vector<vector<qwq>>num(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        num[a[i]].push_back({0,i});
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        num[b[i]].push_back({1,i});
    }

    LL cost=0;
    vector<vector<qwq>>nxt(2,vector<qwq>(n+1,qwq{-1,-1})),pre(2,vector<qwq>(n+1,qwq{-1,-1}));
    for(int i=1;i<=n;i++)
    {
        auto &op=num[i];
        if(op.empty()) continue;
        if((int)op.size()&1)
        {
            cout<<-1<<endl;
            return;
        }

        sort(op.begin(),op.end());

        int len=op.size();
        for(int i=0;i<len;i+=2)
        {
            nxt[op[i].row][op[i].col]=op[i^1];
            pre[op[i^1].row][op[i^1].col]=op[i];
            cost+=op[i^1].col-op[i].col;
        }
    }

    // int cnt=0;
    // auto print=[&]()
    // {
    //     cout<<"test::"<<++cnt<<endl;
    //     for(int i=0;i<=1;i++)
    //     {
    //         cout<<"::"<<i<<"::"<<endl;
    //         for(int j=1;j<=n;j++)
    //             cout<<nxt[i][j].row<<' '<<nxt[i][j].col<<endl;
    //     }        
    // };
    
    cost>>=1;
    vector<pair<int,int>>ans;

    auto update=[&](qwq sufa,qwq sufb,int i,int inverse)
    {
        if(sufa.row==(inverse^1))
        {
            qwq prec,nxtc;
            if(pre[inverse][sufa.col].row==-1)
            {
                nxtc=nxt[inverse][sufa.col];
                prec=pre[nxtc.row][nxtc.col];

                nxt[inverse^1][sufa.col]=nxtc;
                pre[inverse^1][sufa.col]={-1,-1};
                pre[nxtc.row][nxtc.col].row^=1;
                nxt[nxtc.row][nxtc.col]={-1,-1};
            }
            else
            {
                prec=pre[inverse][sufa.col];
                nxtc=nxt[prec.row][prec.col];

                nxt[prec.row][prec.col].row^=1;
                pre[prec.row][prec.col]={-1,-1};
                pre[inverse^1][sufa.col]=prec;
                nxt[inverse^1][sufa.col]={-1,-1};
            }

            nxt[inverse][i].row^=1;
            pre[inverse][i]={-1,-1};
            pre[inverse][sufa.col]={inverse,i};
            nxt[inverse][sufa.col]={-1,-1};

            sufa.row^=1;
            ans.push_back({sufa.col,sufa.col});
            swap(a[sufa.col],b[sufa.col]);
        }

        if(inverse==1)
        {
            ans.push_back({i,sufa.col});
            swap(a[i],b[sufa.col]);
        }
        else
        {
            ans.push_back({sufa.col,i});
            swap(a[sufa.col],b[i]);
        }

        pre[sufa.row][sufa.col]={-1,-1};
        nxt[sufa.row][sufa.col]=sufb;
        pre[sufb.row][sufb.col]={sufa.row,sufa.col};
        nxt[sufb.row][sufb.col]={-1,-1};
    };

    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;
        // print();
        qwq sufa=nxt[0][i],sufb=nxt[1][i];
        if(sufa.col<=sufb.col) update(sufa,sufb,i,0);
        else update(sufb,sufa,i,1);
    }

    cout<<cost<<' '<<ans.size()<<endl;
    for(auto &[u,v]:ans)
        cout<<u<<' '<<v<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}