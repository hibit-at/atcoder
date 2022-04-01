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

int main(void)
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    rep(i, n)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    int maxans = 0;
    int minans = 2e9;
    for (auto p : mp)
    {
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        chmax(maxans, p.second);
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(minans, p.second);
    }
    if (mp.size() < m)
    {
        minans = 0;
    }
    cout << minans << ' ' << maxans << endl;
}