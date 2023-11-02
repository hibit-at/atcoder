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

vector<vector<pair<int, int>>> to;

const int inf = 2e9;

int main(void)
{
    int n;
    cin >> n;
    to.resize(n, vector<pair<int, int>>());
    int tmp = 0;
    int point = 0;
    rep(i, n)
    {
        if (i == 0)
        {
            continue;
        }
        cout << "? 1 " << i + 1 << endl;
        int dist;
        cin >> dist;
        if (tmp < dist)
        {
            point = i;
            tmp = dist;
        }
    }
    rep(i, n)
    {
        if (i == point)
        {
            continue;
        }
        cout << "? " << point + 1 << " " << i + 1 << endl;
        int dist;
        cin >> dist;
        if (tmp < dist)
        {
            tmp = dist;
        }
    }
    cout << "! " << tmp << endl;
    return 0;
}