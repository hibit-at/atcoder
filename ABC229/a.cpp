#include <algorithm>
#include <iostream>
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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "##")
    {
        cout << "Yes" << endl;
    }
    else if (s2 == "##")
    {
        cout << "Yes" << endl;
    }
    else if (s1[0] == '#' && s2[0] == '#')
    {
        cout << "Yes" << endl;
    }
    else if (s1[1] == '#' && s2[1] == '#')
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}