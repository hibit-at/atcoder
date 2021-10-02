#include <algorithm>
#include <iostream>
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

using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

void chmax(int &a, int b) { a = max(a, b); }
void chmin(int &a, int b) { a = min(a, b); }

void print_vector(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main(void)
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n), y(n);
    rep(i, n)
    {
        int tx, ty;
        cin >> tx >> ty;
        x[i] = tx - ty;
        y[i] = tx + ty;
    }
    // print_vector(x);
    // print_vector(y);
    ll x_max = (ll)*max_element(all(x));
    ll x_min = (ll)*min_element(all(x));
    ll y_max = (ll)*max_element(all(y));
    ll y_min = (ll)*min_element(all(y));
    rep(_, q)
    {
        int tq;
        cin >> tq;
        tq--;
        ll xdif = max(x_max - x[tq], x[tq] - x_min);
        ll ydif = max(y_max - y[tq], y[tq] - y_min);
        ll ans = max(xdif, ydif);
        cout << ans << endl;
    }
}