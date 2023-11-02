#include <algorithm>
#include <iostream>
#include <limits>
#include <iomanip>
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
#define rep1(i, n) \
    for (int)      \
        i = 1;     \
    i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T>
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ",";
    }
    cout << endl;
    return;
}

int main(void)
{
    int n;
    cin >> n;
    vector<double> a(n), b(n), c(n);
    double total_c = 0;
    rep(i, n)
    {
        cin >> a[i] >> b[i];
        c[i] = a[i] / b[i];
        total_c += c[i];
    }
    // print_vector<double>(c);
    double target = total_c / 2;
    // debug(target);
    double ans = 0;
    int pos = 0;
    while (target > 0)
    {
        double take_length = min(target, c[pos]);
        ans += take_length * b[pos];
        target -= take_length;
        pos++;
    }
    cout << setprecision(10) << ans << endl;
}