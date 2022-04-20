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
    int t;
    cin >> t;
    rep1(i, t)
    {
        auto solve = [](int t)
        {
            vector<vector<int>> inks(3, vector<int>(4));
            rep(i, 3)
            {
                rep(j, 4)
                {
                    cin >> inks[i][j];
                }
            }
            int left = 1e6;
            vector<int> mins(4, left);
            rep(j, 4)
            {
                rep(i, 3)
                {
                    auto chmin = [](auto &a, auto b)
                    { a = min(a, b); };
                    chmin(mins[j], inks[i][j]);
                }
            }
            auto print_vector = [](auto v)
            {
                for (auto i : v)
                {
                    cout << i << ',';
                }
                cout << endl;
            };
            // print_vector(mins);
            int sum = accumulate(all(mins), 0);
            // debug(sum);
            if (sum < 1e6)
            {
                cout << "Case #" << t << ": ";
                cout << "IMPOSSIBLE" << endl;
                return;
            }
            int pos = 0;
            while (sum > 1e6 && pos < 4)
            {
                int over = sum - 1e6;
                // debug(over);
                if (over > mins[pos])
                {
                    sum -= mins[pos];
                    mins[pos] = 0;
                }
                else
                {
                    sum -= over;
                    mins[pos] -= over;
                }
                pos++;
            }
            auto print_join = [](auto v)
            {
                int size = v.size();
                rep(i, size)
                {
                    if (i < size - 1)
                    {
                        cout << v[i] << ' ';
                    }
                    else
                    {
                        cout << v[i] << endl;
                    }
                }
            };
            cout << "Case #" << t << ": ";
            print_join(mins);
            return;
        };
        solve(i);
    }
    return 0;
}