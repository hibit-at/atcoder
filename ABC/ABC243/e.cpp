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
    vector<int> a(m), b(m), c(m);
    rep(i, m)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        a[i] = x;
        b[i] = y;
        c[i] = z;
        dist[x][y] = z;
        dist[y][x] = z;
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
        if (dist[a[i]][b[i]] < c[i])
        {
            ans++;
            continue;
        }
        rep(j, n)
        {
            if (dist[a[i]][j] + dist[j][b[i]] == c[i])
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}
