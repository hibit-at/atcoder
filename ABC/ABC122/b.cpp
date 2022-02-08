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

bool isValid(char c)
{
    string valid = "ATGC";
    for (char v : valid)
    {
        if (c == v)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

int main(void)
{
    string s;
    cin >> s;
    queue<char> ans;
    int peak = 0;
    for (char c : s)
    {
        if (isValid(c))
        {
            ans.push(c);
        }
        else
        {
            while (ans.size() > 0)
            {
                ans.pop();
            }
        }
        chmax(peak, int(ans.size()));
    }
    cout << peak << endl;
}