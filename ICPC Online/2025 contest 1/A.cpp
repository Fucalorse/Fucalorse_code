#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define LL long long
const int MAX=1e5+90,LEN=26;

struct ID
{
    string name;
    int problem;
    int time;
    string AC;
    bool operator<(const ID &a)const { return time<a.time; }
};

struct qwq
{
    int id;
    int solved_problem;
    int penalty;

    bool operator==(const qwq &a)const { return solved_problem==a.solved_problem&&penalty==a.penalty; }

    bool operator>(const qwq &a)const
    {
        if(solved_problem!=a.solved_problem) return solved_problem>a.solved_problem;
        else return penalty<a.penalty;
    }
};

bool cmp(const qwq &a,const qwq &b)
{
    if(a.solved_problem!=b.solved_problem) return a.solved_problem>b.solved_problem;
    else return a.penalty<b.penalty;    
}

int T,n;

void solve()
{
    cin>>n;

    int tot=0;
    vector<ID>pre,rest;
    unordered_map<string,int>f;
    unordered_map<int,string>ref;
    for(int i=1;i<=n;i++)
    {
        ID cur;
        char c;
        cin>>cur.name>>c>>cur.time>>cur.AC;
        cur.problem=c-'A'+1;

        if(!f.count(cur.name))
        {
            f[cur.name]=++tot;
            ref[tot]=cur.name;
        }

        if(cur.AC[0]=='U') rest.push_back(cur);
        else pre.push_back(cur);
    }

    sort(pre.begin(),pre.end());
    sort(rest.begin(),rest.end());

    vector<vector<int>>cost(tot+1,vector<int>(27,0));
    vector<vector<bool>>solved(tot+1,vector<bool>(27,false));
    for(auto &[name,problem,time,AC]:pre)
    {
        int id=f[name];

        if(solved[id][problem]) continue;

        if(AC[0]=='R') cost[id][problem]+=20;
        else
        {
            cost[id][problem]+=time;
            solved[id][problem]=true;
        }
    }

    vector<qwq>a;
    for(int i=1;i<=tot;i++)
    {
        int total=0,cnt=0;

        for(int j=1;j<=26;j++)
            if(solved[i][j])
            {
                total+=cost[i][j];
                ++cnt;
            }

        a.push_back({i,cnt,total});
    }

    sort(a.begin(),a.end(),cmp);
    qwq best=a.size()?a.front():qwq{0,0,0};

    set<int>st;
    for(auto &cur:a)
        if(cur==best) st.insert(cur.id);

    for(auto &[name,problem,time,AC]:rest)
    {
        int id=f[name];

        if(solved[id][problem]) continue;

        if(AC[0]=='R') cost[id][problem]+=20;
        else
        {
            cost[id][problem]+=time;
            solved[id][problem]=true;
        }        
    }

    for(int i=1;i<=tot;i++)
    {
        int total=0,cnt=0;

        for(int j=1;j<=26;j++)
            if(solved[i][j])
            {
                total+=cost[i][j];
                ++cnt;
            }

        qwq now={i,cnt,total};
        if(now>best||now==best) st.insert(i);
    }

    vector<string>ans;
    for(auto &cur:st)
        ans.push_back(ref[cur]);

    sort(ans.begin(),ans.end());
    for(auto &cur:ans)
        cout<<cur<<' ';
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    cin>>T;
    while(T--) solve();

    return 0;
}