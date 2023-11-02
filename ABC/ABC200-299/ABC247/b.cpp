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
    int n;
    cin >> n;
    map<string, int> surname, firstname;
    vector<string> s(n), t(n);
    rep(i, n)
    {
        cin >> s[i] >> t[i];
        surname[s[i]]++;
        firstname[t[i]]++;
    }
    auto print_map = [](auto mp)
    {
        for (auto p : mp)
        {
            cout << "key : " << p.first << ", value : " << p.second << endl;
        }
    };
    print_map(surname);
    print_map(firstname);
    rep(i, n)
    {
        if (surname[s[i]] > 1 && firstname[t[i]] > 1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}