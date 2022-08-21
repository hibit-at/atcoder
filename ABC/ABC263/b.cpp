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

vector<int> ans;
int n, m;

void dfs()
{
    if (ans.size() == n)
    {
        auto print_vector = [](auto v)
        {
            int size = v.size();
            int cnt = 1;
            for (auto i : v)
            {
                cout << i;
                if (cnt < size)
                {
                    cout << " ";
                }
                else
                {
                    cout << endl;
                }
                cnt++;
            }
        };
        print_vector(ans);
        return;
    }
    if (ans.size() == 0)
    {
        rep1(i, m)
        {
            ans.push_back(i);
            dfs();
            ans.pop_back();
        }
    }
    else
    {
        int tail = ans.back();
        for (int i = tail + 1; i <= m; i++)
        {
            ans.push_back(i);
            dfs();
            ans.pop_back();
        }
    }
}

int main(void)
{
    cin >> n >> m;
    dfs();
}