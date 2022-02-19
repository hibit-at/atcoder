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

string extract(string s, char target)
{
    int n = s.size();
    string ans = "";
    rep(i, n)
    {
        if (s[i] != target)
        {
            ans.push_back(s[i]);
        }
        else
        {
            ans += s.substr(i + 1);
            break;
        }
    }
    return ans;
}

int max_diff(string s, string t)
{
    int n = s.size();
    map<char, int> smap, tmap;
    int ans = 0;
    rep(i, n)
    {
        smap[s[i]]++;
        tmap[t[i]]++;
    }
    for (char c = 'a'; c <= 'z'; c++)
    {
        ans += min(smap[c], tmap[c]);
    }
    return n - ans;
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string ans = "";
    int front_diff = 0;
    string sub = s;
    sort(all(sub));
    rep(i, n)
    {
        for (char c : sub)
        {
            ans.push_back(c);
            if (c != s[i])
            {
                front_diff++;
            }
            string back = extract(sub, c);
            int back_diff = max_diff(back, s.substr(i + 1));
            if (front_diff + back_diff <= k)
            {
                sub = back;
                break;
            }
            ans.pop_back();
            if (c != s[i])
            {
                front_diff--;
            }
        }
    }
    cout << ans << endl;
}