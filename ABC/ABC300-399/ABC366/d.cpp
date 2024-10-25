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

vector<vector<vector<ll>>> computeCumulativeSum3D(const vector<vector<vector<ll>>>& vec) {
    int n = vec.size();
    // [0, n+1) の範囲で累積和を計算するために、サイズを (n+1)x(n+1)x(n+1) にする
    vector<vector<vector<ll>>> cumSum(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                cumSum[i][j][k] = vec[i-1][j-1][k-1]
                                + cumSum[i-1][j][k]
                                + cumSum[i][j-1][k]
                                + cumSum[i][j][k-1]
                                - cumSum[i-1][j-1][k]
                                - cumSum[i-1][j][k-1]
                                - cumSum[i][j-1][k-1]
                                + cumSum[i-1][j-1][k-1];
            }
        }
    }

    return cumSum;
}

int main(){
    int n;
    cin >> n;
    using VI = vector<ll>;
    using VVI = vector<VI>;
    using VVVI = vector<VVI>;
    using VVVVI = vector<VVVI>;
    using VVVVVI = vector<VVVVI>;
    VVVI a(n,VVI(n,VI(n)));
    rep(IJ,n*n){
        rep(k,n){
            int i = IJ/n;
            int j = IJ%n;
            // debug(vector<int>({i,j,k}));
            cin >> a[i][j][k];
        }
    }
    // cout << a << endl;
    VVVI s = computeCumulativeSum3D(a);
    // cout << s << endl;
    int q;
    cin >> q;
    while(q--){
        ll ans = 0;
        ll x, X, y, Y, z, Z;
        cin >> x >> X >> y >> Y >> z >> Z;
        
        ans += s[X][Y][Z]; // [0,X] x [0,Y] x [0,Z] の和

        if (x > 0) ans -= s[x-1][Y][Z]; // [0,x-1] x [0,Y] x [0,Z] の和を引く
        if (y > 0) ans -= s[X][y-1][Z]; // [0,X] x [0,y-1] x [0,Z] の和を引く
        if (z > 0) ans -= s[X][Y][z-1]; // [0,X] x [0,Y] x [0,z-1] の和を引く

        if (x > 0 && y > 0) ans += s[x-1][y-1][Z]; // [0,x-1] x [0,y-1] x [0,Z] の和を足す
        if (x > 0 && z > 0) ans += s[x-1][Y][z-1]; // [0,x-1] x [0,Y] x [0,z-1] の和を足す
        if (y > 0 && z > 0) ans += s[X][y-1][z-1]; // [0,X] x [0,y-1] x [0,z-1] の和を足す

        if (x > 0 && y > 0 && z > 0) ans -= s[x-1][y-1][z-1]; // [0,x-1] x [0,y-1] x [0,z-1] の和を引く

        cout << ans << endl;
    }
}