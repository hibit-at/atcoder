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

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
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
    int n, m, r;
    cin >> n >> m >> r;
    const ll inf = 1e18;
    vector<int> cities(r);
    rep(i, r)
    {
        cin >> cities[i];
        cities[i]--;
    }
    sort(all(cities));
    // print_vector(cities);
    vector<vector<pair<int, int>>> to(n + 1, vector<pair<int, int>>());
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        to[a].push_back({b, c});
        to[b].push_back({a, c});
    }
    // print_vector_vector(dp);
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    // print_vector_vector(dp);
    ll ans = inf;
    do
    {
        // print_vector(cities);
        ll dist = 0;
        rep(i, r - 1)
        {
            int from = cities[i];
            int next = cities[i + 1];
            dist += dp[from][next];
        }
        chmin(ans, dist);
    } while (next_permutation(all(cities)));
    cout << ans << endl;
}