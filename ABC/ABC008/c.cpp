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

void solve(double &ans, vector<int> c)
{
    int n = c.size();
    vector<bool> state(n, true);
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (c[j] % c[i] == 0)
            {
                state[j] = 1 - state[j];
            }
        }
    }
    ans += accumulate(all(state), 0.0);
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> c(n);
    rep(i, n)
    {
        cin >> c[i];
    }
    sort(all(c));
    double ans = 0;
    double deno = 0;
    do
    {
        solve(ans, c);
        deno++;
    } while (next_permutation(all(c)));
    cout << setprecision(20) << ans / deno << endl;
}