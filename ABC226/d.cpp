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
T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void)
{
    int n;
    cin >> n;
    set<pair<int, int>> st;
    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    rep(i, n)
    {
        rep(j, n)
        {
            int tx = x[i] - x[j];
            int ty = y[i] - y[j];
            if (tx == 0 && ty == 0)
            {
                continue;
            }
            int tz = gcd(abs(tx), abs(ty));
            int nx = tx / tz;
            int ny = ty / tz;
            st.insert({nx, ny});
        }
    }
    cout << st.size() << endl;
}