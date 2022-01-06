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
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n + 1; i++)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;

typedef long long ll;

int main(void)
{
    int n;
    string s;
    cin >> n >> s;
    deque<int> q;
    rep(i, n)
    {
        char c = s[i];
        int j = i + 1;
        if (c == 'L')
        {
            q.push_front(j);
        }
        if (c == 'R')
        {
            q.push_back(j);
        }
        if (c == 'A')
        {
            if (q.size() == 0)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                cout << q.front() << endl;
                q.pop_front();
            }
        }
        if (c == 'B')
        {
            if (q.size() <= 1)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                int tmp1 = q.front();
                q.pop_front();
                cout << q.front() << endl;
                q.pop_front();
                q.push_front(tmp1);
            }
        }
        if (c == 'C')
        {
            if (q.size() <= 2)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                int tmp1 = q.front();
                q.pop_front();
                int tmp2 = q.front();
                q.pop_front();
                cout << q.front() << endl;
                q.pop_front();
                q.push_front(tmp2);
                q.push_front(tmp1);
            }
        }
        if (c == 'D')
        {
            if (q.size() == 0)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                cout << q.back() << endl;
                q.pop_back();
            }
        }
        if (c == 'E')
        {
            if (q.size() <= 1)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                int tmp1 = q.back();
                q.pop_back();
                cout << q.back() << endl;
                q.pop_back();
                q.push_back(tmp1);
            }
        }
        if (c == 'F')
        {
            if (q.size() <= 2)
            {
                cout << "ERROR" << endl;
            }
            else
            {
                int tmp1 = q.back();
                q.pop_back();
                int tmp2 = q.back();
                q.pop_back();
                cout << q.back() << endl;
                q.pop_back();
                q.push_back(tmp2);
                q.push_back(tmp1);
            }
        }
    }
}