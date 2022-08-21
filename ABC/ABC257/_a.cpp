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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> pawn(k);
    rep(i, k)
    {
        cin >> pawn[i];
        pawn[i]--;
    }
    while (q--)
    {
        int L;
        cin >> L;
        L--;
        if (L == k - 1)
        {
            pawn[L] = min(n - 1, pawn[L] + 1);
        }
        else
        {
            int dif = pawn[L + 1] - pawn[L];
            if (dif > 1)
            {
                pawn[L]++;
            }
        }
        auto print_join = [](auto v)
        {
            int size = v.size();
            rep(i, size)
            {
                if (i < size - 1)
                {
                    cout << v[i] + 1 << ' ';
                }
                else
                {
                    cout << v[i] + 1 << endl;
                }
            }
        };
        // print_join(pawn);
    }
    rep(i, k)
    {
        pawn[i]++;
    }
    auto print_join = [](auto v)
    {
        int size = v.size();
        rep(i, size)
        {
            if (i < size - 1)
            {
                cout << v[i] << ' ';
            }
            else
            {
                cout << v[i] << endl;
            }
        }
    };
    print_join(pawn);
}