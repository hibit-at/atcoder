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

int main()
{
    string t;
    cin >> t;
    if (t[0] == '1')
    {
        cout << "No" << endl;
        return 0;
    }
    vector<int> s(10);
    rep(i, 10)
    {
        s[i] = t[i] - '0';
    }
    vector<int> lanes(7);
    int lane0 = s[6];
    lanes[0] = lane0 > 0;
    int lane1 = s[3];
    lanes[1] = lane1 > 0;
    int lane2 = s[1] + s[7];
    lanes[2] = lane2 > 0;
    int lane3 = s[0] + s[4];
    lanes[3] = lane3 > 0;
    int lane4 = s[2] + s[8];
    lanes[4] = lane4 > 0;
    int lane5 = s[5];
    lanes[5] = lane5 > 0;
    int lane6 = s[9];
    lanes[6] = lane6 > 0;
    // debug(lanes);
    string u;
    int pos = 0;
    while (pos < 7)
    {
        int head = lanes[pos];
        while (lanes[pos] == head)
        {
            pos++;
            if(pos == 7){
                break;
            }
        }
        u.push_back(head + '0');
    }
    // debug(u);
    int m = u.size();
    rep(i, m - 3 + 1)
    {
        if (u.substr(i, 3) == "101")
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}