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
    vector<vector<int>> maze(3, vector<int>(3, 0));
    vector<int> h(3), w(3);
    cin >> h >> w;
    int ans = 0;
    rep1(A, 30)
    {
        rep1(B, 30)
        {
            rep1(D, 30)
            {
                rep1(E, 30)
                {
                    int C = h[0] - A - B;
                    int F = h[1] - D - E;
                    int G = w[0] - A - D;
                    int H = w[1] - B - E;
                    int I = h[2] - G - H;
                    int I_check = w[2] - C - F;
                    if (I != I_check)
                    {
                        continue;
                    }
                    if (C < 1)
                    {
                        continue;
                    }
                    if (F < 1)
                    {
                        continue;
                    }
                    if (G < 1)
                    {
                        continue;
                    }
                    if (H < 1)
                    {
                        continue;
                    }
                    if (I < 1)
                    {
                        continue;
                    }
                    // cout << C << F << G << H << I << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}