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
void print_vector(vector<T> v)
{
    for (T i : v)
    {
        cout << i << ',';
    }
    cout << endl;
    return;
}

bool func(int range, int n, int k, vector<int> sum_o)
{
    rep(i, n - range + 1)
    {
        int part_o = sum_o[i + range] - sum_o[i];
        if (part_o <= k)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<int> sum_o(n + 1);
    rep(i, n)
    {
        sum_o[i + 1] = s[i] == '.';
        sum_o[i + 1] += sum_o[i];
    }
    int ok = 0;
    int ng = n + 1;
    while (abs(ok - ng) > 1)
    {
        int range = (ok + ng) / 2;
        if (func(range, n, k, sum_o))
        {
            ok = range;
        }
        else
        {
            ng = range;
        }
    }
    cout << ok << endl;
}