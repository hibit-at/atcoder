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

int n;
vector<vector<int>> a;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int dfs(vector<pair<int, int>> vp, vector<bool> used)
{
    if (vp.size() == n)
    {
        int ans = 0;
        for (auto p : vp)
        {
            ans ^= a[p.first][p.second];
        }
        return ans;
    }

    int person1 = 0;
    rep1(i, 2 * n)
    {
        if (!used[i])
        {
            person1 = i;
            break;
        }
    }
    used[person1] = true;

    int ans = 0;
    rep1(person2, 2 * n)
    {
        if (!used[person2])
        {
            vp.push_back({person1, person2});
            used[person2] = true;
            chmax(ans, dfs(vp, used));
            vp.pop_back();
            used[person2] = false;
        }
    }

    return ans;
}

int main(void)
{
    cin >> n;
    a.resize(2 * n);
    rep1(i, 2 * n - 1)
    {
        a[i].resize(2 * n + 1);
        for (int j = i + 1; j <= 2 * n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<bool> used(2 * n + 1);
    vector<pair<int, int>> vp;
    cout << dfs(vp, used) << endl;
}