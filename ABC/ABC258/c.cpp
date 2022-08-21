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

int main(void)
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    mint shift = 0;
    modint::set_mod(n);
    while (q--)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1)
        {
            shift -= x;
        }
        if (t == 2)
        {
            mint pos = shift + x - 1;
            cout << s[pos.val()] << endl;
        }
    }
}