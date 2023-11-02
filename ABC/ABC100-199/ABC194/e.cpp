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

int main(void)
{
    int n, m;
    cin >> n >> m;
    queue<int> a;
    rep(i, n)
    {
        int x;
        cin >> x;
        a.push(x);
    }
    int ans = n;
    queue<int> q;
    vector<int> state(n + 1);
    set<int> zero;
    rep(i, n + 1)
    {
        zero.insert(i);
    }
    while (a.size() > 0)
    {
        int now = a.front();
        q.push(now);
        state[now]++;
        if (state[now] == 1)
        {
            zero.erase(now);
        }
        a.pop();
        if (q.size() < m)
        {
            continue;
        }
        if (q.size() > m)
        {
            int now = q.front();
            state[now]--;
            if (state[now] == 0)
            {
                zero.insert(now);
            }
            q.pop();
        }
        auto chmin = [](auto &a, auto b)
        { a = min(a, b); };
        chmin(ans, *zero.begin());
    }
    cout << ans << endl;
    return 0;
}