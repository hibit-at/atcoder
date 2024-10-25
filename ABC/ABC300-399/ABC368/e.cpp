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
    int n,m;
    cin >> n >> m;
    ll first_delay;
    cin >> first_delay;
    vector<ll> x(m,0);
    // x[0] = first_delay;
    ll first_start = 0;
    vector<set<pair<pair<ll,ll>,pair<ll,ll>>>> to(n);
    vector<pair<pair<ll,ll>,pair<ll,ll>>> edge(m);
    rep(i,m){
        ll a,b,s,t;
        cin >> a >> b >> s >> t;
        a--;
        b--;
        to[a].insert({{s,t},{i,b}});
        edge[i] = {{a,b},{s,t}};
    }
    using S = pair<ll,ll>;
    priority_queue<S> pq;
    pq.push({first_delay,0});
    while(pq.size()){
        auto [now_delay,now_idx] = pq.top();
        pq.pop();
        if(now_delay <= x[now_idx]){
            continue;
        }
        x[now_idx] = now_delay;
        auto [original_s, original_t] = edge[now_idx].second;
        auto [now_pos,next_pos] = edge[now_idx].first;
        int to_sz = to[next_pos].size();
        auto itr = to[next_pos].upper_bound({{original_t,0},{0,0}});
        if(itr == to[next_pos].begin()){
            continue;
        }
        itr--;
        while(++itr != to[next_pos].end()){
            auto [ST,IB] = *itr;
            // auto [a,b] = AB;
            auto [s,t] = ST;
            auto [next_idx,b] = IB;
            if(original_t > s){
                continue;
            }
            ll delay = 0;
            if(s < original_t + now_delay){
                delay = original_t + now_delay - s;
                // debug(delay);
            }
            if(delay <= x[next_idx]){
                continue;
            }
            pq.push({delay,next_idx});
        }
    }
    // debug(x);
    vector<ll> ans(m-1);
    rep(i,m-1){
        ans[i] = x[i+1];
    }
    cout << ans << endl;
}