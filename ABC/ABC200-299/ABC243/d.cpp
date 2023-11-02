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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

int main(void)
{
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    reverse(all(s));
    int buf = 0;
    char last = 'L';
    string t;
    rep(i, n)
    {
        if (s[i] == 'U')
        {
            buf++;
        }
        if (s[i] != 'U')
        {
            if (buf > 0)
            {
                buf--;
                continue;
            }
            t.push_back(s[i]);
        }
    }
    while (buf--)
    {
        t.push_back('U');
    }
    reverse(all(t));
    // debug(t);
    for (char c : t)
    {
        if (c == 'U')
        {
            x /= 2;
        }
        if (c == 'L')
        {
            x *= 2;
        }
        if (c == 'R')
        {
            x *= 2;
            x++;
        }
    }
    cout << x << endl;
}