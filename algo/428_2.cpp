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

vector<vector<int>> func(int n, int L, int R)
{
    if (L > R)
    {
        return {};
    }
    if (n == 0)
    {
        return {{}};
    }
    vector<vector<int>> ans;
    for (vector<int> f : func(n - 1, L, R))
    {
        reverse(all(f));
        f.push_back(L);
        reverse(all(f));
        ans.push_back(f);
    }
    for (vector<int> f : func(n, L + 1, R))
    {
        ans.push_back(f);
    }
    return ans;
}

int main(void)
{
    int n, L, R;
    cin >> n >> L >> R;
    vector<vector<int>> ans = func(n, L, R);
    for (vector<int> a : ans)
    {
        for (int i : a)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}