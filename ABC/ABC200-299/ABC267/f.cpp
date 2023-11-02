#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <stack>
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
// #define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ":" << val << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, multiset<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

#include <bits/stdc++.h>
using namespace std;

/* Rerooting: 全方位木 DP
    問題ごとに以下を書き換える
    - 型DPと単位元
    - 型DPに対する二項演算 merge
    - まとめたDPを用いて新たな部分木のDPを計算する add_root
    計算量: O(N)
*/
struct Rerooting
{
    /* start 問題ごとに書き換え */
    struct DP
    { // DP の型
        long long dp;
        DP(long long dp_) : dp(dp_) {}
    };
    const DP identity = DP(-1); // 単位元(末端の値は add_root(identity) になるので注意)
    function<DP(DP, DP)> merge = [](DP dp_cum, DP d) -> DP
    {
        return DP(max(dp_cum.dp, d.dp));
    };
    function<DP(DP)> add_root = [](DP d) -> DP
    {
        return DP(d.dp + 1);
    };
    /* end 問題ごとに書き換え */

    // グラフの定義
    struct Edge
    {
        int to;
    };
    using Graph = vector<vector<Edge>>;

    vector<vector<DP>> dp; // dp[v][i]: vから出るi番目の有向辺に対応する部分木のDP
    vector<DP> ans;        // ans[v]: 頂点vを根とする木の答え
    Graph G;

    Rerooting(int N) : G(N)
    {
        dp.resize(N);
        ans.assign(N, identity);
    }

    void add_edge(int a, int b)
    {
        G[a].push_back({b});
    }
    void build()
    {
        dfs(0);           // 普通に木DP
        bfs(0, identity); // 残りの部分木に対応するDPを計算
    }

    DP dfs(int v, int p = -1)
    { // 頂点v, 親p
        DP dp_cum = identity;
        int deg = G[v].size();
        dp[v] = vector<DP>(deg, identity);
        for (int i = 0; i < deg; i++)
        {
            int u = G[v][i].to;
            if (u == p)
                continue;
            dp[v][i] = dfs(u, v);
            dp_cum = merge(dp_cum, dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void bfs(int v, const DP &dp_p, int p = -1)
    { // bfs だが、実装が楽なので中身は dfs になっている
        int deg = G[v].size();
        for (int i = 0; i < deg; i++)
        { // 前のbfsで計算した有向辺に対応する部分木のDPを保存
            if (G[v][i].to == p)
                dp[v][i] = dp_p;
        }
        vector<DP> dp_l(deg + 1, identity), dp_r(deg + 1, identity); // 累積merge
        for (int i = 0; i < deg; i++)
        {
            dp_l[i + 1] = merge(dp_l[i], dp[v][i]);
        }
        for (int i = deg - 1; i >= 0; i--)
        {
            dp_r[i] = merge(dp_r[i + 1], dp[v][i]);
        }

        ans[v] = add_root(dp_l[deg]); // 頂点 v の答え

        for (int i = 0; i < deg; i++)
        { // 一つ隣の頂点に対しても同様に計算
            int u = G[v][i].to;
            if (u == p)
                continue;
            bfs(u, add_root(merge(dp_l[i], dp_r[i + 1])), v);
        }
    }
};

int main()
{
    int N;
    cin >> N;
    Rerooting reroot(N);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        reroot.add_edge(u, v);
        reroot.add_edge(v, u);
    }
    reroot.build();

    for (int i = 0; i < N; i++)
    {
        cout << "頂点" << i + 1 << ": " << reroot.ans[i].dp << endl;
    }
    int q;
    cin >> q;
    rep(i, q)
    {
        int u, k;
        cin >> u >> k;
    }
}
