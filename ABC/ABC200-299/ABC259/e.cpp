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
    map<int, multiset<int>> mp;
    rep(i, n)
    {
        int m;
        cin >> m;
        rep(j, m)
        {
            int p, m;
            cin >> p >> m;
            mp[p].insert(m);
        }
    }
    for (auto &[key, val] : mp)
    {
        while (val.size() > 2)
        {
            val.erase(val.begin());
        }
        for (int i : val)
        {
            cout << i << ",";
        }
        cout << endl;
    }
    
}