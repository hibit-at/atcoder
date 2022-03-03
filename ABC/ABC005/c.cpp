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
const int inf = 1e9;

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (T i : v)
        {
            if (i == inf)
            {
                cout << "-,";
            }
            else
            {
                cout << i << ",";
            }
        }
        cout << endl;
    }
}

int main(void)
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> maze(h, vector<char>(w, '.'));
    int sh, sw;
    int gh, gw;
    rep(i, h)
    {
        rep(j, w)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 's')
            {
                sh = i;
                sw = j;
            }
            if (maze[i][j] == 'g')
            {
                gh = i;
                gw = j;
                maze[i][j] = '.';
            }
        }
    }
    // print_vector_vector(maze);
    vector<int> dh = {1, -1, 0, 0};
    vector<int> dw = {0, 0, 1, -1};
    deque<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, inf));
    dist[sh][sw] = 0;
    q.push_back({sh, sw});
    while (q.size() > 0)
    {
        auto now = q.front();
        q.pop_front();
        // print_vector_vector(dist);
        int nh = now.first;
        int nw = now.second;
        rep(i, 4)
        {
            int th = nh + dh[i];
            int tw = nw + dw[i];
            if (th < 0)
            {
                continue;
            }
            if (th >= h)
            {
                continue;
            }
            if (tw < 0)
            {
                continue;
            }
            if (tw >= w)
            {
                continue;
            }
            // load
            if (maze[th][tw] == '.')
            {
                if (dist[nh][nw] < dist[th][tw])
                {
                    dist[th][tw] = dist[nh][nw];
                    q.push_front({th, tw});
                }
            }
            // wall
            if (maze[th][tw] == '#')
            {
                if (dist[nh][nw] + 1 < dist[th][tw])
                {
                    dist[th][tw] = dist[nh][nw] + 1;
                    q.push_back({th, tw});
                }
            }
        }
    }
    if (dist[gh][gw] <= 2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}