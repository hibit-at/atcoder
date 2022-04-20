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
    int t, r, c;
    cin >> t;
    rep1(i, t)
    {
        // debug(t);
        cout << "Case #" << i << ':' << endl;
        int r, c;
        cin >> r >> c;
        int max_r = 2 * r + 1;
        int max_c = 2 * c + 1;
        vector<vector<char>> maze(max_r, vector<char>(max_c, '.'));
        rep(i, max_r)
        {
            rep(j, max_c)
            {
                maze[i][j] = '-';
            }
            i++;
        }
        rep(i, max_r)
        {
            rep(j, max_c)
            {
                maze[i][j] = '|';
                j++;
            }
        }
        rep(i, max_r)
        {
            rep(j, max_c)
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    maze[i][j] = '+';
                }
            }
        }
        auto print_vector_vector = [](auto vv)
        {
            for (auto v : vv)
            {
                for (auto i : v)
                {
                    cout << i;
                }
                cout << endl;
            }
        };
        rep(i, 2)
        {
            rep(j, 2)
            {
                maze[i][j] = '.';
            }
        }
        print_vector_vector(maze);
    }
}