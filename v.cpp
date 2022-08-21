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
using mint = modint1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<int>> maze(h + 2, vector<int>(w + 2));
    using S = pair<int, pair<int, int>>;
    priority_queue<S, vector<S>, greater<S>> pq;
    rep1(i, h)
    {
        rep1(j, w)
        {
            int a;
            cin >> a;
            maze[i][j] = a;
            pq.push({a, {i, j}});
        }
    }
    vector<vector<mint>> dp(h + 2, vector<mint>(w + 2,1));
    while (pq.size())
    {
        auto [val, pos] = pq.top();
        pq.pop();
        auto [i, j] = pos;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        rep(k, 4)
        {
            if (maze[i][j] < maze[i + dx[k]][j + dy[k]])
            {
                dp[i + dx[k]][j + dy[k]] += dp[i][j];
            }
        }
    }
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i.val() << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(dp);
    mint ans = 0;
    rep1(i,h){
        rep1(j,w){
            ans += dp[i][j];
        }
    }
    cout << ans.val() << endl;
}