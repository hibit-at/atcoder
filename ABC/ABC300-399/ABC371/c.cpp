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
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define all(A) A.begin(), A.end()
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
    int n = v.size();
    int m = v[0].size();
    int p = v[0][0].size();
    rep(k, p)
    {
        os << "k = " << k << endl;
        rep(i, n)
        {
            rep(j, m)
            {
                os << v[i][j][k];
                if (j < m - 1)
                {
                    os << " ";
                }
                else
                {
                    os << endl;
                }
            }
        }
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

template <typename T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T, vector<T>, greater<T>> mpq)
{
    while (mpq.size())
    {
        os << mpq.top() << " ";
        mpq.pop();
    }
    return os;
}

// グラフが同型かどうかを確認するヘルパー関数（隣接行列版）
bool areIsomorphicMatrix(const vector<vector<int>>& g1, const vector<vector<int>>& g2, const vector<int>& perm) {
    int n = g1.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // 頂点 perm[i] と perm[j] の間の接続が g2 の同じ場所にあるか確認
            if (g1[i][j] != g2[perm[i]][perm[j]]) {
                return false;
            }
        }
    }
    return true;
}

// グラフが同型かどうかを確認する関数（隣接行列版）
bool isIsomorphicMatrix(vector<vector<int>> g1, vector<vector<int>> g2) {
    int n = g1.size();
    
    // サイズが異なる場合は即座にfalse
    if (n != g2.size()) return false;
    
    // 頂点の順列を生成
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
        perm[i] = i;
    }
    
    // 全順列を試して同型か確認
    do {
        if (areIsomorphicMatrix(g1, g2, perm)) {
            return true;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    
    return false;
}


int main(){
    int n;
    cin >> n;
    int mg;
    cin >> mg;
    vector<vector<int>> tog(n,vector<int>(n));
    int cnt_g = 0;
    rep(i,mg){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        tog[u][v] = 1;
        tog[v][u] = 1;
    }
    int mh;
    cin >> mh;
    vector<pair<int,int>> AB(mh);
    cin >> AB;
    rep(i,mh){
        AB[i].first--;
        AB[i].second--;
    }
    debug(AB);
    vector<vector<int>> cost(n,vector<int>(n));
    rep(i,n){
        rep(j,n-1-i){
            int x;
            cin >> x;
            cost[i][i+j+1] = x;
            cost[i+j+1][i] = x;
        }
    }
    cout << cost << endl;
    vector<int> p(n);
    iota(all(p),0);
    int ans = 1e9;
    do{
        int tmp = 0;
        // debug(p);
        vector<vector<int>> toh(n,vector<int>(n));
        rep(i,mh){
            auto [a,b] = AB[i];
            int pa = p[a];
            int pb = p[b];
            toh[pa][pb] = 1;
            toh[pb][pa] = 1;
        }
        vector<vector<int>> tox(n,vector<int>(n));
        rep(i,n){
            rep(j,n){
                tox[i][j] = toh[i][j]^tog[i][j];
            }
        }
        rep(i,n){
            rep(j,n){
                tmp += tox[i][j]*cost[i][j];
            }
        }
        tmp /= 2;
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(ans,tmp);
    }while(next_permutation(all(p)));
    cout << ans << endl;
}