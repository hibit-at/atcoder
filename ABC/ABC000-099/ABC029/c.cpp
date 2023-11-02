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

string ans;
int n;

void dfs()
{
    int size = ans.size();
    if (size == n)
    {
        cout << ans << endl;
        return;
    }
    rep(i, 3)
    {
        ans.push_back(i + 'a');
        dfs();
        ans.pop_back();
    }
    return;
}

int main(void)
{
    cin >> n;
    dfs();
}