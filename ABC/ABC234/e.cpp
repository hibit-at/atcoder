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

vector<ll> a;
map<ll, bool> mp;

void dfs(ll n)
{
    if (n < 0)
    {
        return;
    }
    if (n > 1e18)
    {
        return;
    }
    if (mp[n] == true)
    {
        return;
    }
    
    mp[n] = true;
    if (n < 10)
    {
        for (int i = -9; i < 10; i++)
        {
            ll next_num = n + i;
            if (next_num < 0)
            {
                continue;
            }
            if (next_num > 9)
            {
                continue;
            }
            if (i == 0 && next_num == 0)
            {
                continue;
            }
            dfs(10 * n + next_num);
        }
    }
    ll first = n % 10;
    ll second = (n / 10) % 10;
    ll next_num = 2 * first - second;
    if (next_num < 0)
    {
        return;
    }
    if (next_num > 9)
    {
        return;
    }
    a.push_back(n);
    dfs(10 * n + next_num);
}

int main(void)
{
    dfs(0);
    cout << a.size() << endl;
    for (auto p : mp)
    {
        cout << p.first << "," << p.second << endl;
    }
}