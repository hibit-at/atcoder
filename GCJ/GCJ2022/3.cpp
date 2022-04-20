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
            // debug(t);
            int n;
            cin >> n;
            vector<int> s(n);
            rep(i, n)
            {
                cin >> s[i];
            }
            sort(all(s));
            queue<int> q;
            for (int i : s)
            {
                q.push(i);
            }
            auto print_front = [](auto q)
            {
                while (q.size() > 0)
                {
                    cout << q.front() << ',';
                    q.pop();
                }
                cout << endl;
            };
            // print_front(q);
            int ans = 0;
            int count = 1;
            while (q.size() > 0)
            {
                int now = q.front();
                q.pop();
                if (now >= count)
                {
                    ans++;
                    count++;
                }
            }
            // debug(ans);
            cout << "Case #" << t << ": " << ans << endl;
        };
        solve(i);
    }
}