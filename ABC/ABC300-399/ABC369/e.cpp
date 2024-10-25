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

int main(){
    #define int ll
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> dp(n,vector<ll>(n,1e12));
    vector<pair<pair<ll,ll>,ll>> edge(2*m);
    rep(i,n){
        dp[i][i] = 0;
    }
    rep(i,m){
        ll u,v,t;
        cin >> u >> v >> t;
        u--;
        v--;
        edge[i] = {{u,v},t};
        edge[i+m] = {{v,u},t};
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(dp[u][v],t);
        chmin(dp[v][u],t);
    }
    rep(k,n){
        rep(i,n){
            rep(j,n){
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                chmin(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    // cout << dp << endl;
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector<int> b(k);
        cin >> b;
        sort(all(b));
        rep(i,k){
            b[i]--;
        }
        ll ans = LLONG_MAX;
        do{
            rep(state,1<<k){
                vector<int> c(k);
                rep(i,k){
                    if(state>>i&1){
                        c[i] = b[i]+m;
                    }else{
                        c[i] = b[i];
                    }
                }
                int now = 0;
                ll tmp = 0;
                rep(i,k){
                    auto [to,cost] = edge[c[i]];
                    auto [from,next] = to;
                    ll cost_from = dp[now][from];
                    ll cost_next = dp[from][next];
                    tmp += cost_from;
                    tmp += cost;
                    now = next;
                }
                tmp += dp[now][n-1];
                auto chmin = [](auto &a, auto b)
                { a = min(a, b); };
                chmin(ans,tmp);
            }
        }while(next_permutation(all(b)));
        cout << ans << endl;
    }
}