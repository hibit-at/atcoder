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

int main(void)
{
    #define int ll
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    ll forward = 0;
    rep(i, n)
    {
        forward += a[i] == i + 1;
    }
    vector<map<int, int>> pos(n + 1);
    rep(i, n)
    {
        pos[a[i]][i + 1]++;
    }
    ll backward = 0;
    rep(i, n)
    {
        // debug(i);
        int target = a[i];
        if (pos[i+1].size() == 0)
        {
            continue;
        }
        auto print_map = [](auto mp)
        {
            for (auto p : mp)
            {
                cout << "key : " << p.first << ", value : " << p.second << endl;
            }
        };
        // debug(target);
        // print_map(pos[i+1]);
        if (pos[i+1].count(target) > 0 && i+1 != target)
        {
            backward++;
        }
    }
    // debug(forward);
    // debug(backward);
    ll ans = forward * (forward - 1) / 2;
    ans += backward / 2;
    cout << ans << endl;
}