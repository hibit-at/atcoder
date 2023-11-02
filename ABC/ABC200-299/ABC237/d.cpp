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
#include <deque>

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
    string s;
    cin >> s;
    deque<int> d;
    d.push_back(n);
    reverse(all(s));
    rep(i, n)
    {
        int x = n - 1 - i;
        if (s[i] == 'R')
        {
            d.push_front(x);
        }
        else
        {
            d.push_back(x);
        }
    }
    while (d.size() > 0)
    {
        cout << d.front();
        d.pop_front();
        if (d.size() > 0)
        {
            cout << ' ';
        }
    }
    cout << endl;
}