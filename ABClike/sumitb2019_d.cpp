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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> t(n);
    rep(i, n)
    {
        t[i] = s[i] - '0';
    }
    set<string> ans;
    rep(i, 10)
    {
        rep(j, 10)
        {
            rep(k, 10)
            {
                bool first = false;
                bool second = false;
                bool third = false;
                rep(pos, n)
                {
                    if (!first && t[pos] == i)
                    {
                        first = true;
                        continue;
                    }
                    if (first && !second && t[pos] == j)
                    {
                        second = true;
                        continue;
                    }
                    if (second && !third && t[pos] == k)
                    {
                        third = true;
                    }
                    if (third)
                    {
                        string tmp = "xxx";
                        tmp[0] = i + '0';
                        tmp[1] = j + '0';
                        tmp[2] = k + '0';
                        ans.insert(tmp);
                    }
                }
            }
        }
    }
    cout << ans.size() << endl;
}