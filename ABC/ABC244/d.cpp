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

int main(void)
{
    char s1, s2, s3;
    char t1, t2, t3;
    cin >> s1 >> s2 >> s3;
    cin >> t1 >> t2 >> t3;
    int diff_s = 0, diff_t = 0;
    if (s1 != 'R')
    {
        diff_s++;
    }
    if (s2 != 'G')
    {
        diff_s++;
    }
    if (s3 != 'B')
    {
        diff_s++;
    }
    if (t1 != 'R')
    {
        diff_t++;
    }
    if (t2 != 'G')
    {
        diff_t++;
    }
    if (t3 != 'B')
    {
        diff_t++;
    }
    int group_s = 0, group_t = 0;
    if (diff_s == 2)
    {
        group_s = 1;
    }
    else
    {
        group_s = 0;
    }
    if (diff_t == 2)
    {
        group_t = 1;
    }
    else
    {
        group_t = 0;
    }
    if (group_s == group_t)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}