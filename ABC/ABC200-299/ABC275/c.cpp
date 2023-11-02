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
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << "i = " << i << endl;
        os << v[i];
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ":" << val << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, multiset<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

struct Point
{
    double x = 0;
    double y = 0;

    void rot(double angle)
    {
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
    }

    void rot(int degree)
    {
        double pi = atan(1) * 4;
        double angle = double(degree) / 180 * pi;
        rot(angle);
    }

    double norm()
    {
        return sqrt(x * x + y * y);
    }

    double arg()
    {
        return atan2(y, x);
    }

    double operator*(Point &other)
    {
        return x * other.x + y * other.y;
    }

    double operator^(Point &other)
    {
        return x * other.y - y * other.x;
    }

    Point operator+(Point &other)
    {
        Point ans;
        ans.x = x + other.x;
        ans.y = y + other.y;
        return ans;
    }

    Point operator-(Point &other)
    {
        Point ans;
        ans.x = x - other.x;
        ans.y = y - other.y;
        return ans;
    }

    int ccw(Point B, Point C)
    {
        Point A = *this;
        Point AB = B - A;
        Point AC = C - A;
        double cross = AB ^ AC;
        if (cross > 0)
        {
            return 1;
        }
        else if (cross == 0)
        {
            return 0;
        }
        else
        {
            return -1;
        }
        return true;
    }
};

ostream &operator<<(ostream &os, Point p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

int main()
{
    vector<string> maze(9);
    cin >> maze;
    auto print_maze = [](auto maze)
    {
        int n = maze.size();
        int m = maze[0].size();
        rep(i, n)
        {
            rep(j, m) { cout << maze[i][j]; }
            cout << endl;
        }
    };
    // print_maze(maze);
    // cout << maze << endl;
    int ans = 0;
    set<vector<int>> square_check;
    rep(a, 81)
    {
        rep(b, 81)
        {
            int ax = a % 9;
            int ay = a / 9;
            int bx = b % 9;
            int by = b / 9;
            int ix = bx - ax;
            int iy = by - ay;
            if (ix == 0 && iy == 0)
            {
                continue;
            }
            int cx = bx + iy;
            int cy = by - ix;
            if (cx < 0 || 9 <= cx)
            {
                continue;
            }
            if (cy < 0 || 9 <= cy)
            {
                continue;
            }
            int dx = cx - ix;
            int dy = cy - iy;
            if (dx < 0 || 9 <= dx)
            {
                continue;
            }
            if (dy < 0 || 9 <= dy)
            {
                continue;
            }
            vector<int> square_index;
            square_index.push_back(ax * 9 + ay);
            square_index.push_back(bx * 9 + by);
            square_index.push_back(cx * 9 + cy);
            square_index.push_back(dx * 9 + dy);
            sort(all(square_index));
            if (square_check.count(square_index))
            {
                continue;
            }
            square_check.insert(square_index);
            // debug(ax);
            // debug(ay);
            // debug(bx);
            // debug(by);
            // debug(cx);
            // debug(cy);
            // debug(dx);
            // debug(dy);
            int pawn_check = 0;
            pawn_check += maze[ax][ay] == '#';
            pawn_check += maze[bx][by] == '#';
            pawn_check += maze[cx][cy] == '#';
            pawn_check += maze[dx][dy] == '#';
            ans += pawn_check == 4;
        }
    }
    cout << ans << endl;
}