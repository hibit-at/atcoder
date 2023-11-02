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
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
    int x = 0;
    int y = 0;
    int dir = 0;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c : s)
    {
        if (c == 'S')
        {
            x += dx[dir];
            y += dy[dir];
        }
        if (c == 'R')
        {
            dir = (dir + 1) % 4;
        }
    }
    cout << x << ' ' << y << endl;
}