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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

bool check(vector<int> skill, int x)
{
    for (int s : skill)
    {
        if (s < x)
        {
            return false;
        }
    }
    return true;
}

const int inf = 2e9;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n)
    {
        cin >> c[i];
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    int ans = inf;
    rep(i, 1 << n)
    {
        int cost = 0;
        vector<int> skill(m);
        rep(j, n)
        {
            bool bit = (i >> j) & 1;
            if (bit)
            {
                cost += c[j];
                rep(k, m)
                {
                    skill[k] += a[j][k];
                }
            }
        }
        // print_vector(skill);
        if (check(skill, x))
        {
            chmin(ans, cost);
        }
    }
    if (ans == inf)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
}