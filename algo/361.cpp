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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> a, b;
    rep(i, n)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    rep(i, m)
    {
        int x;
        cin >> x;
        b.push(x);
    }
    int ans = 0;
    while (a.size() > 0 && b.size() > 0)
    {
        int now_a = a.top();
        int now_b = b.top();
        // debug(now_a);
        // debug(now_b);
        if (now_a <= now_b)
        {
            a.pop();
            ans++;
        }
        b.pop();
    }
    cout << ans << endl;
}