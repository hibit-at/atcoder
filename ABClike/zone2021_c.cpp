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

int n;
vector<vector<int>> a;

template <typename T>
void chmin(T &a, T b) { a = min(a, b); }

template <typename T>
void chmax(T &a, T b) { a = max(a, b); }

template <typename T>
void print_vector_vector(vector<vector<T>> vv)
{
    for (vector<T> v : vv)
    {
        for (int i : v)
        {
            cout << i << ",";
        }
        cout << endl;
    }
}

bool func(int mid)
{
    set<int> st;
    rep(i, n)
    {
        int tmp = 0;
        rep(j, 5)
        {
            if (a[i][j] >= mid)
            {
                tmp += 1 << j;
            }
        }
        st.insert(tmp);
    }
    int m = st.size();
    vector<int> vt;
    for (auto s : st)
    {
        vt.push_back(s);
    }
    rep(i, m)
    {
        rep(j, m)
        {
            rep(k, m)
            {
                int check = 0;
                check |= vt[i];
                check |= vt[j];
                check |= vt[k];
                if (check == 31)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    cin >> n;
    a.resize(n, vector<int>(5));
    rep(i, n)
    {
        rep(j, 5)
        {
            cin >> a[i][j];
        }
    }
    // print_vector_vector(a);
    int ok = 0;
    int ng = 1e9 + 1;
    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if (func(mid))
        {
            ok = mid;
        }
        else
        {
            ng = mid;
        }
    }
    cout << ok << endl;
}