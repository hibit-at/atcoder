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
void chmin(T &a, T b) { a = min(a, b); }

int main(void)
{
    int n;
    cin >> n;
    map<char, int> mp;
    string s = "ABCDEF";
    for (auto c : s)
    {
        mp[c] = 1e9;
    }
    rep1(i, n)
    {
        char p;
        string v;
        cin >> p >> v;
        if (v == "AC")
        {
            chmin(mp[p], i);
        }
    }
    for (auto c : s)
    {
        cout << mp[c] << endl;
    }
}