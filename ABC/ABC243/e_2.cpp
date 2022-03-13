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

const ll inf = 1e9 + 7;

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
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> dist(n, vector<ll>(n, inf));
    rep(i, n)
    {
        dist[i][i] = 0;
    }
    vector<int> a_memo(m), b_memo(m), c_memo(m);
    rep(i, m)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        a_memo[i] = a;
        b_memo[i] = b;
        c_memo[i] = c;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    // print_vector_vector(dist);
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                chmin(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = 0;
    // print_vector_vector(dist);
    rep(i, m)
    {
        int a = a_memo[i];
        int b = b_memo[i];
        int c = c_memo[i];
        rep(j, n)
        {
            if (j == a || j == b)
            {
                continue;
            }
            if (dist[a][j] + dist[j][b] <= c)
            {
                ans++;
                break;
                // debug(ans);
            }
        }
    }
    cout << ans << endl;
}
