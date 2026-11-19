#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// #define endl '\n'
#define LL long long

const int MAXN = 1e5 + 5;

int n;
int a[MAXN];

set<int> all;
set<pair<int,int>> st;

int cnt = 0;

void dfs(int a, int b) {
    if (a>b) swap(a,b);
    if (st.count({a,b})) return;

    if (a==b) return;
    st.insert({a,b});

    if (all.insert(a^b).second){
        dfs(a, a ^ b);
        dfs(b, a ^ b);
    }
    if (all.insert(a|b).second){
        dfs(a, a | b);
        dfs(b, a | b);
    }
    if (all.insert(a&b).second){
        dfs(a, a & b);
        dfs(b, a & b);
    }
    ++cnt;
}

void solve() {
    map<string,int> mp;
    mp["ycx"] = mp["whl"] = mp["jjh"] = 0;
    while (1){
        string s;
        cin >> s;
        mp[s]++;

        for (auto& [s,v]:mp){
            cout << s << ' ' << v << ' ';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

// g++ G_.cpp -O2 -o .\out.exe && .\out.exe < in.txt