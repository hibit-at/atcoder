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

bool match(vector<vector<char>> &a, vector<vector<char>> &b, int start_i, int start_j)
{
    int m = b.size();
    rep(i, m)
    {
        rep(j, m)
        {
            if (a[start_i + i][start_j + j] != b[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    vector<vector<char>> b(m, vector<char>(m));
    rep(i, n)
    {
        string s;
        cin >> s;
        rep(j, n)
        {
            a[i][j] = s[j];
        }
    }
    rep(i, m)
    {
        string s;
        cin >> s;
        rep(j, m)
        {
            b[i][j] = s[j];
        }
    }
    rep(i, n - m + 1)
    {
        rep(j, n - m + 1)
        {
            if (match(a, b, i, j))
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}