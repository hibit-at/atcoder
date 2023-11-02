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

int dig(int n)
{
    int ans = 0;
    while (n)
    {
        ans++;
        n /= 10;
    }
    return ans;
}

string zfill(int n)
{
    string ans = "";
    int m = n;
    while (n)
    {
        ans.push_back(n % 10 + '0');
        n /= 10;
    }
    rep(i, 6 - dig(m))
    {
        ans.push_back('0');
    }
    reverse(all(ans));
    return ans;
}

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> zaz;
    vector<int> p(m), y(m);
    rep(i, m)
    {
        cin >> p[i] >> y[i];
        zaz[p[i]].push_back(y[i]);
    }
    for (auto z : zaz)
    {
        auto vec = z.second;
        sort(all(vec));
        vec.erase(unique(all(vec)), vec.end());
        // print_vector(vec);
        zaz[z.first] = vec;
    }
    rep(i, m)
    {
        int lower = lower_bound(all(zaz[p[i]]), y[i]) - zaz[p[i]].begin() + 1;
        cout << zfill(p[i]) << zfill(lower) << endl;
    }
}