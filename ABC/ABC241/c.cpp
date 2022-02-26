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
    int n;
    cin >> n;
    vector<vector<char>> maze(n, vector<char>(n));
    rep(i, n)
    {
        rep(j, n)
        {
            cin >> maze[i][j];
        }
    }
    rep(i, n)
    {
        rep(j, n)
        {
            // horizontal
            if (j + 5 < n)
            {
                int check = 0;
                rep(k, 6)
                {
                    check += (maze[i][j + k] == '#');
                }
                if (check >= 4)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            // vertical
            if (i + 5 < n)
            {
                int check = 0;
                rep(k, 6)
                {
                    check += (maze[i + k][j] == '#');
                }
                if (check >= 4)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            // diagonal 1
            if (i + 5 < n && j + 5 < n)
            {
                int check = 0;
                rep(k, 6)
                {
                    check += (maze[i + k][j + k] == '#');
                }
                if (check >= 4)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
            // diagonal 2
            if (i - 5 >= 0 && j + 5 < n)
            {
                int check = 0;
                rep(k, 6)
                {
                    check += (maze[i - k][j + k] == '#');
                }
                if (check >= 4)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}