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
    vector<int> x(n), y(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }
    string s;
    cin >> s;
    map<int, vector<pair<ll, char>>> mp;
    rep(i, n)
    {
        mp[y[i]].push_back({x[i], s[i]});
    }
    for (auto p : mp)
    {
        int ypos = p.first;
        // debug(ypos);
        sort(all(p.second));
        string check = "";
        for (auto xpos : p.second)
        {
            // cout << xpos.first << '-' << xpos.second << ',';
            check.push_back(xpos.second);
        }
        // cout << endl;
        // debug(check);
        int size = check.size();
        rep(i, size - 1)
        {
            if (check[i] == 'R' && check[i + 1] == 'L')
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}