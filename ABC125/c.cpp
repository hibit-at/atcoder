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

template <typename T>
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<int> left(n), right(n);
    rep(i, n)
    {
        if (i == 0)
        {
            left[i] = a[i];
        }
        else
        {
            left[i] = gcd(left[i - 1], a[i]);
        }
    }
    // print_vector(left);
    rep(i, n)
    {
        int pos = n - 1 - i;
        if (i == 0)
        {
            right[pos] = a[pos];
        }
        else
        {
            right[pos] = gcd(right[pos + 1], a[pos]);
        }
    }
    // print_vector(right);
    int ans = 0;
    rep(i, n)
    {
        if (i == 0)
        {
            chmax(ans, right[i + 1]);
        }
        else if (i < n - 1)
        {
            chmax(ans, gcd(left[i - 1], right[i + 1]));
        }
        else
        {
            chmax(ans, left[i - 1]);
        }
    }
    cout << ans << endl;
}