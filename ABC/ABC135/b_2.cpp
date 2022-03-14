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

vector<int> swap_vector(int a, int b, vector<int> p)
{
    swap(p[a], p[b]);
    return p;
}

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

bool isSorted(vector<int> p)
{
    int n = p.size();
    rep(i, n - 1)
    {
        if (p[i] > p[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n)
    {
        cin >> p[i];
    }
    if(isSorted(p)){
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // debug(i);
            // debug(j);
            // print_vector(swap_vector(i, j, p));
            if (isSorted(swap_vector(i, j, p)))
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}