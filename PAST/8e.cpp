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
void chmin(T &a, T b) { a = min(a, b); }

template <typename S, typename T>
void print_map(map<S, T> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first << ", value : " << p.second << endl;
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<int> c(n), p(n);
    rep(i, n)
    {
        cin >> c[i];
    }
    rep(i, n)
    {
        cin >> p[i];
    }
    rep(i, n)
    {
        if (mp[c[i]] == 0)
        {
            mp[c[i]] = p[i];
        }
        else
        {
            chmin(mp[c[i]], p[i]);
        }
    }
    if (mp.size() < k)
    {
        cout << -1 << endl;
    }
    else
    {
        ll ans = 0;
        vector<int> v;
        for (auto p : mp)
        {
            v.push_back(p.second);
        }
        sort(all(v));
        cout << accumulate(v.begin(), v.begin() + k, 0ll);
    }
}