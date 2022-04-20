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

int main(void)
{
    map<int, int> xm;
    map<int, int> ym;
    rep(i, 3)
    {
        int x, y;
        cin >> x >> y;
        xm[x]++;
        ym[y]++;
    }
    auto print_map = [](auto mp)
    {
        for (auto p : mp)
        {
            cout << "key : " << p.first << ", value : " << p.second << endl;
        }
    };
    // print_map(xm);
    // print_map(ym);
    for (auto p : xm)
    {
        if (p.second == 1)
        {
            cout << p.first;
        }
    }
    cout << ' ';
    for (auto p : ym)
    {
        if (p.second == 1)
        {
            cout << p.first << endl;
        }
    }
}