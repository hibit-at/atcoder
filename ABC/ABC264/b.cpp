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

string solve(int r, int c)
{
    r -= 7;
    c -= 7;
    r = abs(r);
    c = abs(c);
    int man = max(r, c);
    if (man % 2 == 0)
    {
        return "white";
    }
    else
    {
        return "black";
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    // rep(i, 15)
    // {
    //     rep(j, 15)
    //     {
    //         cout << solve(i, j) << ",";
    //     }
    //     cout << endl;
    // }
    r--;
    c--;
    cout << solve(r, c) << endl;
}