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

ll score(int p, int q, vector<vector<ll>> &a)
{
    int n = a.size();
    ll ans = 0;
    rep(i, n)
    {
        ans += max(a[i][p], a[i][q]);
    }
    return ans;
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    rep(i, m)
    {
        for (int j = i + 1; j < m; j++)
        {
            chmax(ans, score(i, j, a));
        }
    }
    cout << ans << endl;
}