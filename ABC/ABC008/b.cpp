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
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    int n;
    cin >> n;
    map<string, int> mp;
    int peak = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        mp[s]++;
        chmax(peak, mp[s]);
    }
    for (auto p : mp)
    {
        if (p.second == peak)
        {
            cout << p.first << endl;
            return 0;
        }
    }
}