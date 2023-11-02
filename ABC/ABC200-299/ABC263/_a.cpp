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
    map<int, int> mp;
    rep(i, 5)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    auto F = mp.begin();
    auto S = next(mp.begin());
    if (F->second == 2 && S->second == 3)
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (F->second == 3 && S->second == 2)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}