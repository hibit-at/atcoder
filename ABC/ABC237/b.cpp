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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> mat(h, vector<int>(w));
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> mat[i][j];
        }
    }
    rep(i, w)
    {
        rep(j, h)
        {
            cout << mat[j][i];
            if (j < h - 1)
            {
                cout << ' ';
            }
        }
        cout << endl;
    }
}