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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int h, w;
vector<vector<char>> maze;

void print_maze(vector<vector<char>> maze)
{
    int n = maze.size();
    int m = maze[0].size();
    rep(i, n)
    {
        rep(j, m) { cout << maze[i][j]; }
        cout << endl;
    }
}

int main(void)
{
    cin >> h >> w;
    rep(i, h + 2)
    {
        maze[i].resize(w + 2, '#');
    }
    rep1(i, h)
    {
        rep1(j, w)
        {
            char c;
            cin >> c;
            maze[i][j] = c;
        }
    }
    print_maze(maze);
}