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
    string s, t;
    cin >> s >> t;
    using S = pair<char, int>;
    vector<S> sp;
    int n = s.size();
    int pos = 0;
    while (pos < n)
    {
        char head = s[pos];
        int buf = 0;
        while (s[pos] == head && pos < n)
        {
            buf++;
            pos++;
        }
        sp.push_back({head, buf});
    }
    vector<S> tp;
    int m = t.size();
    pos = 0;
    while (pos < m)
    {
        char head = t[pos];
        int buf = 0;
        while (t[pos] == head && pos < m)
        {
            buf++;
            pos++;
        }
        tp.push_back({head, buf});
    }
    auto print_vector_pair = [](auto v)
    {
        for (auto i : v)
        {
            cout << "(" << i.first << "," << i.second << ")"
                 << " ";
        }
        cout << endl;
    };
    // print_vector_pair(sp);
    // print_vector_pair(tp);
    if (sp.size() != tp.size())
    {
        cout << "No" << endl;
        return 0;
    }
    n = sp.size();
    rep(i, n)
    {
        if (sp[i].first != tp[i].first)
        {
            cout << "No" << endl;
            return 0;
        }
        if (sp[i].second != tp[i].second)
        {
            if (sp[i].second > 1 && tp[i].second > 1 && sp[i].second < tp[i].second)
            {
                continue;
            }
            else
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}