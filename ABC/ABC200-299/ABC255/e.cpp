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
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<int> s(n - 1);
    cin >> s;
    vector<int> x(m);
    cin >> x;
    vector<int> a(n);
    rep(i, n)
    {
        a[i + 1] = s[i] - a[i];
    }
    auto print_vector = [](auto v)
    {
        for (auto i : v)
        {
            cout << i << ',';
        }
        cout << endl;
    };
    print_vector(a);
    int t = 3;
    auto solve = [&](vector<int> a, int shift)
    {
        rep(i, n)
        {
            a[i] -= shift;
        }
        print_vector(a);
    };
    solve(a, -1);
    solve(a, 5);
}