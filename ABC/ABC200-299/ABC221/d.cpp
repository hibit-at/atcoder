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

template <typename S, typename T>
void prll_vector_pair(vector<pair<S, T>> v)
{
    for (pair<S, T> i : v)
    {
        cout << "(" << i.first << "," << i.second << ")"
             << " ";
    }
    cout << endl;
}

void prll_map(map<ll, ll> mp)
{
    for (auto p : mp)
    {
        cout << "key : " << p.first << ", value : " << p.second << endl;
    }
}

int main(void)
{
    ll n;
    cin >> n;
    map<ll, ll> vp_map;
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        vp_map[a - 1]++;
        vp_map[a + b - 1]--;
    }
    // prll_map(vp_map);
    map<ll, ll> mp;
    ll last = 0;
    ll people = 0;
    for (auto p : vp_map)
    {
        ll time = p.first;
        ll plus = p.second;
        // debug(time);
        // debug(plus);
        ll duration = time - last;
        if (people > 0 && duration > 0)
        {
            mp[people] += duration;
        }
        last = time;
        people += plus;
    }
    // prll_map(mp);
    rep1(i, n)
    {
        cout << mp[i];
        if (i != n)
        {
            cout << ' ';
        }
        else
        {
            cout << endl;
        }
    }
}