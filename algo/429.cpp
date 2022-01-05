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

vector<string> func(int n, int L, int R)
{
    if (n == 0)
    {
        return {""};
    }
    if (L > R)
    {
        return {};
    }
    vector<string> ans = {};
    for (string f : func(n - 1, L, R))
    {
        ans.push_back(to_string(L) + f);
    }
    for (string f : func(n, L + 1, R))
    {
        ans.push_back(f);
    }
    return ans;
}

int main(void)
{
    int L, R;
    cin >> L >> R;
    vector<string> vs = func(9, 0, 9);
    ll ans = 0;
    for (string s : vs)
    {
        ll num = stoll(s);
        if(num < L){
            continue;
        }
        if(num > R){
            break;
        }
        ans += num;
    }
    cout << ans << endl;
}