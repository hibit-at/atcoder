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

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<string> maze(h);
    cin >> maze;
    int pos = 0;
    rep(i, 2 * h * w)
    {
        int now_h = pos / w;
        int now_w = pos % w;
        // debug(now_h);
        // debug(now_w);
        char c = maze[now_h][now_w];
        if (c == 'U')
        {
            if (now_h == 0)
            {
                cout << now_h + 1 << " " << now_w + 1 << endl;
                return 0;
            }
            else
            {
                pos -= w;
            }
        }
        if (c == 'D')
        {
            if (now_h == h - 1)
            {
                cout << now_h + 1 << " " << now_w + 1 << endl;
                return 0;
            }
            else
            {
                pos += w;
            }
        }
        if (c == 'L')
        {
            if (now_w == 0)
            {
                cout << now_h + 1 << " " << now_w + 1 << endl;
                return 0;
            }
            else
            {
                pos--;
            }
        }
        if (c == 'R')
        {
            if (now_w == w - 1)
            {
                cout << now_h + 1 << " " << now_w + 1 << endl;
                return 0;
            }
            else
            {
                pos++;
            }
        }
    }
    cout << -1 << endl;
}