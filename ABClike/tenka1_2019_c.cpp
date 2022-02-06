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
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> black(n + 1);
    vector<int> white(n + 1);
    rep1(i, n)
    {
        black[i] = s[i - 1] == '#';
        white[i] = s[i - 1] == '.';
        black[i] += black[i - 1];
        white[i] += white[i - 1];
    }
    int ans = 1e9;
    rep(i, n + 1)
    {
        chmin(ans, black[i] + white[n] - white[i]);
    }
    cout << ans << endl;
}