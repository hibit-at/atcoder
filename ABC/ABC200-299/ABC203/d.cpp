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

// global variant

int n, k;
vector<vector<int>> a;

// function

bool solve(int target)
{
    vector<vector<bool>> b(n, vector<bool>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            b[i][j] = (a[i][j] > target);
        }
    }
    vector<vector<int>> s(n + 1, vector<int>(n + 1));
    rep1(i, n)
    {
        rep1(j, n)
        {
            s[i][j] = b[i - 1][j - 1];
            s[i][j] += s[i][j - 1];
        }
        rep1(j, n)
        {
            s[i][j] += s[i - 1][j];
        }
    }
    rep(i, n - k + 1)
    {
        rep(j, n - k + 1)
        {
            int start_h = i;
            int start_w = j;
            int end_h = start_h + k;
            int end_w = start_w + k;
            int count = s[end_h][end_w] - s[start_h][end_w] - s[end_h][start_w] + s[start_h][start_w];
            if (count < (k * k) / 2 + 1)
            {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    cin >> n >> k;
    a.resize(n, vector<int>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> a[i][j];
        }
    }
    int ng = -1;
    int ok = 1e9 + 1;
    while (abs(ng - ok) > 1)
    {
        int mid = ng + ok;
        mid /= 2;
        if (solve(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}