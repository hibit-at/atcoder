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

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

#include <atcoder/fenwicktree>
using namespace atcoder;

int main(void)
{
    map<char, int> mp;
    mp['a'] = 0;
    mp['t'] = 1;
    mp['c'] = 2;
    mp['o'] = 3;
    mp['d'] = 4;
    mp['e'] = 5;
    mp['r'] = 6;
    vector<int> a;
    string s;
    cin >> s;
    for (char c : s)
    {
        a.push_back(mp[c]);
    }
    auto print_vector = [](auto v)
    {
        int size = v.size();
        int cnt = 1;
        for (auto i : v)
        {
            cout << i;
            if (cnt < size)
            {
                cout << " ";
            }
            else
            {
                cout << endl;
            }
            cnt++;
        }
    };
    // print_vector(a);
    fenwick_tree<int> ft(7);
    int ans = 0;
    rep(i, 7)
    {
        int now = a[i];
        ans += ft.sum(a[i] + 1, 7);
        ft.add(a[i], 1);
    }
    cout << ans << endl;
}