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

const ll inf = 1e18;

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> to(n, vector<ll>(n, inf));
    rep(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        to[a][b] = c;
    }
    rep(i, n)
    {
        to[i][i] = 0;
    }
    // vector<vector<ll>> to(n, vector<ll>(inf));
    // print_vector_vector(to);
    ll ans = 0;
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                chmin(to[i][j], to[i][k] + to[k][j]);
                if (to[i][j] < inf)
                {
                    ans += to[i][j];
                }
            }
        }
    }
    cout << ans << endl;
}