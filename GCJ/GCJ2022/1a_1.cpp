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
            string s;
            cin >> s;
            string ans = "";
            int n = s.size();
            vector<pair<char, int>> vp;
            int pos = 0;
            while (pos < n)
            {
                char start = s[pos];
                int buf = 0;
                while (s[pos] == start)
                {
                    pos++;
                    buf++;
                }
                vp.push_back({start, buf});
            }
            auto print_vector_pair = [](auto v)
            {
                for (auto i : v)
                {
                    cout << "(" << i.first << "," << i.second << ")"
                         << " ";
                }
                cout << endl;
            };
            // print_vector_pair(vp);
            int m = vp.size();
            rep(i, m - 1)
            {
                auto now = vp[i];
                rep(j, now.second)
                {
                    ans.push_back(now.first);
                }
                if (vp[i].first < vp[i + 1].first)
                {
                    rep(j, now.second)
                    {
                        ans.push_back(now.first);
                    }
                }
            }
            auto last = vp.back();
            rep(i, last.second)
            {
                ans.push_back(last.first);
            }
            cout << "Case #" << t << ": " << ans << endl;
        };
        solve(i);
    }
}