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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<string> ans;
    rep(i, n - m + 1)
    {
        bool okay = true;
        rep(j, m)
        {
            if (s[i + j] != '?' && s[i + j] != t[j])
            {
                okay = false;
            }
        }
        if (!okay)
        {
            continue;
        }
        string tmp = "";
        rep(j, n)
        {
            tmp.push_back(s[j] == '?' ? 'a' : s[j]);
        }
        rep(j, m)
        {
            tmp[i + j] = t[j];
        }
        ans.push_back(tmp);
    }
    sort(all(ans));
    if (ans.size() > 0)
    {
        cout << ans[0] << endl;
    }
    else
    {
        cout << "UNRESTORABLE" << endl;
    }
}