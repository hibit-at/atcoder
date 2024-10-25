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

void fillLayeredValues(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int layers = (n + 1) / 2;  // レイヤー数は (n + 1) / 2 で計算可能

    for (int layer = 0; layer < layers; ++layer) {
        // 外周の上下左右をそれぞれ layer ごとに埋める
        for (int i = layer; i < n - layer; ++i) {
            matrix[layer][i] = layer;                // 上辺
            matrix[n - 1 - layer][i] = layer;        // 下辺
            matrix[i][layer] = layer;                // 左辺
            matrix[i][n - 1 - layer] = layer;        // 右辺
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    cin >> a;
    // cout << a << endl;
    rep(i,n){
        rep(j,n){

        }
    }
    auto rotate = [&](vector<vector<char>> org){
        vector<vector<char>> res(n,vector<char>(n));
        rep(i,n){
            rep(j,n){
                res[j][n-i-1] = org[i][j]; 
            }
        }
        return res;
    };
    vector<vector<char>> rot1 = rotate(a);
    vector<vector<char>> rot2 = rotate(rot1);
    vector<vector<char>> rot3 = rotate(rot2);
    // cout << rot1 << endl;
    // cout << rot2 << endl;
    // cout << rot3 << endl;
    vector<vector<int>> weight(n,vector<int>(n));
    fillLayeredValues(weight);
    // cout << weight << endl;
    vector<vector<char>> ans(n,vector<char>(n));
    rep(i,n){
        rep(j,n){
            if(weight[i][j]%4==0){
                cout << rot1[i][j];
            }
            if(weight[i][j]%4==1){
                cout << rot2[i][j];
            }
            if(weight[i][j]%4==2){
                cout << rot3[i][j];
            }
            if(weight[i][j]%4==3){
                cout << a[i][j];
            }
        }
        cout << endl;
    }
}