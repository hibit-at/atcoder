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
vector<ll> ans;
ll tmp_sum = 0;
ll target = 0;
int n;
bool okay = false;

void dfs(int pos)
{
    if (okay)
    {
        return;
    }
    // debug(pos);
    // debug(tmp_sum);
    if (pos >= 2 * n)
    {
        return;
    }
    if (tmp_sum == target)
    {
        auto print_join = [](auto v)
        {
            int size = v.size();
            rep(i, size)
            {
                if (i < size - 1)
                {
                    cout << v[i] << ' ';
                }
                else
                {
                    cout << v[i] << endl;
                }
            }
        };
        print_join(ans);
        okay = true;
        return;
    }
    dfs(pos + 1);
    tmp_sum += a[pos];
    ans.push_back(a[pos]);
    dfs(pos + 1);
    ans.pop_back();
    tmp_sum -= a[pos];
}

void solve(int t)
{
    // debug(t);
    cin >> n;
    a.resize(n);
    rep(i, n)
    {
        a[i] = 2 * i + 1;
    }
    auto print_join = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    print_join(a);
    rep(i, n)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    ll sum = accumulate(all(a), 0LL);
    target = sum / 2;
    ans.resize(0);
    tmp_sum = 0;
    okay = false;
    dfs(0);
}

int main(void)
{
    int t;
    cin >> t;
    rep1(i, t)
    {
        solve(i);
    }
}