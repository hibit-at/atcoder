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
    int ha, wa;
    cin >> ha >> wa;
    vector<vector<int>> a(ha, vector<int>(wa));
    cin >> a;
    int hb, wb;
    cin >> hb >> wb;
    vector<vector<int>> b(hb, vector<int>(wb));
    cin >> b;
    auto print_vector_vector = [](auto vv)
    {
        for (auto v : vv)
        {
            for (auto i : v)
            {
                cout << i << ',';
            }
            cout << endl;
        }
    };
    // print_vector_vector(a);
    // print_vector_vector(b);
    rep(h_state, 1 << ha)
    {
        if (h_state == 0)
        {
            continue;
        }
        rep(w_state, 1 << wa)
        {
            if (w_state == 0)
            {
                continue;
            }
            int hd = __builtin_popcount(h_state);
            int wd = __builtin_popcount(w_state);
            if (hd != hb)
            {
                continue;
            }
            if (wd != wb)
            {
                continue;
            }
            // debug(hd);
            // debug(wd);
            vector<vector<int>> d(hb, vector<int>(wb));
            int i_count = 0;
            rep(i, ha)
            {
                if (!(h_state >> i & 1))
                {
                    continue;
                }
                int j_count = 0;
                rep(j, wa)
                {
                    if (!(w_state >> j & 1))
                    {
                        continue;
                    }
                    d[i_count][j_count] = a[i][j];
                    j_count++;
                }
                i_count++;
            }
            // print_vector_vector(d);
            if (d == b)
            {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}