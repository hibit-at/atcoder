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

vector<vector<int>> bfs_grid(vector<vector<char>> maze, int sh, int sw)
{
    const int inf = 1e9;
    int h = maze.size();
    int w = maze[0].size();
    vector<vector<int>> dist(h, vector<int>(w,inf));
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    queue<pair<int, int>> q;
    q.push({sh, sw});
    dist[sh][sw] = 0;
    while (q.size() > 0)
    {
        auto now = q.front();
        q.pop();
        int now_h = now.first;
        int now_w = now.second;
        rep(i, 4)
        {
            int next_h = now_h + dh[i];
            int next_w = now_w + dw[i];
            if (next_h < 0 || h <= next_h)
            {
                continue;
            }
            if (next_w < 0 || w <= next_w)
            {
                continue;
            }
            if (maze[next_h][next_w] == '#')
            {
                continue;
            }
            if (dist[next_h][next_w] <= dist[now_h][now_w] + 1)
            {
                continue;
            }
            dist[next_h][next_w] = dist[now_h][now_w] + 1;
            q.push({next_h, next_w});
        }
    }
    return dist;
}

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

int main(void)
{
    int r, c;
    cin >> r >> c;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    sy --;
    sx --;
    gy --;
    gx --;
    vector<vector<char>> maze(r, vector<char>(c, '#'));
    rep(i, r)
    {
        rep(j, c)
        {
            cin >> maze[i][j];
        }
    }
    // print_maze(maze);
    vector<vector<int>> dist = bfs_grid(maze, sy, sx);
    // print_vector_vector(dist);
    cout << dist[gy][gx] << endl;
}