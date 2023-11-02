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

#include <atcoder/string>
using namespace atcoder;

int main(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, n)
    {
        string t = s.substr(i);
        vector<int> z = z_algorithm(t);
        auto print_vector = [](auto v)
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
        print_vector(z);
    }
    cout << ans << endl;
}