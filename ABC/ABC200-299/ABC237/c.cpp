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

bool isKaibun(string s)
{
    int n = s.size();
    rep(i, n)
    {
        int back = n - 1 - i;
        if (s[i] != s[back])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    deque<char> d;
    string s;
    cin >> s;
    for (char c : s)
    {
        d.push_back(c);
    }
    while (d.front() == 'a' && d.back() == 'a' && d.size() > 1)
    {
        d.pop_front();
        d.pop_back();
        if (d.size() == 0)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    string t = "";
    while (d.size() > 0)
    {
        t.push_back(d.front());
        d.pop_front();
    }
    while (t.back() == 'a')
    {
        t.pop_back();
    }
    if (isKaibun(t))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}