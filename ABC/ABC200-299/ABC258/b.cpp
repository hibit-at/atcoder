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
    int n;
    cin >> n;
    vector<string> a(n);
    cin >> a;
    auto print_maze = [](auto maze)
    {
        int n = maze.size();
        int m = maze[0].size();
        rep(i, n)
        {
            rep(j, m) { cout << maze[i][j]; }
            cout << endl;
        }
    };
    // print_maze(a);
    // vector<string> ans;
    string ans = "1";
    auto chmax = [](auto &a, auto b)
    { a = max(a, b); };
    rep(i, n)
    {
        rep(j, n)
        {
            vector<int> dx = {1, -1, 0, 0, 1, 1, -1, -1};
            vector<int> dy = {0, 0, 1, -1, 1, -1, 1, -1};
            rep(d, 8)
            {
                string t = "";
                rep(k, n)
                {
                    int next_i = i + dx[d] * k;
                    int next_j = j + dy[d] * k;
                    next_i %= n;
                    next_i += n;
                    next_i %= n;
                    next_j %= n;
                    next_j += n;
                    next_j %= n;
                    // debug(next_i);
                    // debug(next_j);
                    t.push_back(a[next_i][next_j]);
                }
                // debug(t);
                chmax(ans, t);
            }
        }
    }
    cout << ans << endl;
}