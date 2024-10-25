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
struct pairset
{
    std::set<std::pair<int, int>> data;
    std::map<int, int> count;
    int size;

    pairset()
    {
        data.insert({INT_MIN, INT_MIN});
        data.insert({INT_MAX, INT_MAX});
        size = 0;
    }

    bool contains(int x)
    {
        auto itr = prev(data.lower_bound({x + 1, x + 1}));
        auto [L, R] = *itr;
        return L <= x && x <= R;
    }

    bool insert(int x)
    {
        count[x]++;
        auto next_itr = data.lower_bound({x + 1, x + 1});
        auto itr = prev(next_itr);
        auto [L, R] = *itr;
        auto [next_L, next_R] = *next_itr;
        if (L <= x && x <= R)
        {
            size++;
            return false;
        }
        if (R == x - 1)
        {
            if (next_L == x + 1)
            {
                data.erase(itr);
                data.erase(next_itr);
                data.insert({L, next_R});
            }
            else
            {
                data.erase(itr);
                data.insert({L, x});
            }
        }
        else
        {
            if (next_L == x + 1)
            {
                data.erase(next_itr);
                data.insert({x, next_R});
            }
            else
            {
                data.insert({x, x});
            }
        }
        size++;
        return true;
    }

    bool remove(int x)
    {
        if (count[x] == 0)
        {
            return false;
        }
        count[x]--;
        if (count[x])
        {
            size--;
            return false;
        }
        auto next_itr = data.lower_bound({x + 1, x + 1});
        auto itr = prev(next_itr);
        auto [L, R] = *itr;
        auto [next_L, next_R] = *next_itr;
        if (x < L || R < x)
        {
            return false;
        }
        if (L == R)
        {
            data.erase(itr);
        }
        else if (x == L)
        {
            data.erase(itr);
            data.insert({x + 1, R});
        }
        else if (x == R)
        {
            data.erase(itr);
            data.insert({L, x - 1});
        }
        else
        {
            data.erase(itr);
            data.insert({L, x - 1});
            data.insert({x + 1, R});
        }
        size--;
        return true;
    }

    int mex(int x = 0)
    {
        auto [L, R] = *prev(data.lower_bound({x + 1, x + 1}));
        if (L <= x && x <= R)
        {
            return R + 1;
        }
        else
        {
            return x;
        }
    }

    int left_mex(int x = 0){
        auto [L,R] = *prev(data.lower_bound({x+1,x+1}));
        if(L <= x && x <= R){
            return L-1;
        }else{
            return x;
        }
    }

    int min()
    {
        auto itr = *data.lower_bound({INT_MIN + 1, INT_MIN + 1});
        return itr.first;
    }

    int max()
    {
        auto itr = *prev(data.lower_bound({INT_MAX, INT_MAX}));
        return itr.second;
    }
};
int main(){
    ll h,w,q;
    cin >> h >> w >> q;
    vector<pairset> vert_to_hori(h);
    vector<pairset> hori_to_vert(w);
    rep(i,q){
        int r,c;
        cin >> r >> c;
        r--;
        c--;
        if(!vert_to_hori[r].contains(c)){
            vert_to_hori[r].insert(c);
        }else{
            int start = vert_to_hori[r].left_mex(c);
            int end = vert_to_hori[r].mex(c);
            // debug(vector<int>({start,end}));
            if(start>=0){
                vert_to_hori[r].insert(start);
                hori_to_vert[start].insert(r);
            }
            if(end<w){
                vert_to_hori[r].insert(end);
                hori_to_vert[end].insert(r);
            }
        }
        if(!hori_to_vert[c].contains(r)){
            hori_to_vert[c].insert(r);
        }else{
            int start = hori_to_vert[c].left_mex(r);
            int end = hori_to_vert[c].mex(r);
            if(start>=0){
                hori_to_vert[c].insert(start);
                vert_to_hori[start].insert(c);
            }
            if(end<h){
                hori_to_vert[c].insert(end);
                vert_to_hori[end].insert(c);
            }
        }
    }
    ll ans = h*w;
    rep(i,h){
        int m = vert_to_hori[i].data.size();
        auto itr = vert_to_hori[i].data.begin();
        int cnt = 0;
        while(itr != vert_to_hori[i].data.end()){
            ll L = itr->first;
            ll R = itr->second;
            if(0<cnt&&cnt<m-1){
                ans -= R-L+1;
            }
            itr++;
            cnt++;
        }
    }
    cout << ans << endl;
}