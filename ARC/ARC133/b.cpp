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
size_t longest_increasing_subsequence(const vector<T> &a, bool strict)
{
    vector<T> lis;
    for (auto &p : a)
    {
        typename vector<T>::iterator it;
        if (strict)
            it = lower_bound(begin(lis), end(lis), p);
        else
            it = upper_bound(begin(lis), end(lis), p);
        if (end(lis) == it)
            lis.emplace_back(p);
        else
            *it = p;
    }
    return lis.size();
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n)
    {
        cin >> p[i];
    }
    rep(i, n)
    {
        cin >> q[i];
    }
    vector<pair<int, int>> v(0);
    vector<int> p_index(n + 1);
    rep1(i, n)
    {
        p_index[p[i - 1]] = i;
    }
    vector<int> q_index(n + 1);
    rep1(i, n)
    {
        q_index[q[i - 1]] = i;
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    // print_vector(p_index);
    rep1(i, n)
    {
        int pos = 0;
        while (pos + i <= n)
        {
            pos += i;
            v.push_back({p_index[i], -q_index[pos]});
        }
    }
    auto print_vector_pair = [](auto v)
    {
        for (auto i : v)
        {
            cout << "(" << i.first << "," << i.second << ")"
                 << " ";
        }
        cout << endl;
    };
    sort(all(v));
    // print_vector_pair(v);
    vector<int> lis(0);
    for (auto p : v)
    {
        lis.push_back(-p.second);
    }
    // print_vector(lis);
    cout << longest_increasing_subsequence(lis, true) << endl;
}