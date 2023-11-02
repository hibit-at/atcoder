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

#include <atcoder/modint>
using namespace atcoder;
using mint = modint;

int main()
{
    int n, q;
    string s;
    cin >> n >> s >> q;
    bool flip = false;
    modint::set_mod(2 * n);
    while (q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) swap(s[(mint(a - 1) + n * flip).val()], s[(mint(b - 1) + n * flip).val()]);
        if (t == 2) flip ^= 1;
    }
    rep(i, 2 * n) cout << s[(mint(i) + n * flip).val()];
    cout << endl;
}