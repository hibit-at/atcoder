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
#include <complex>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i < n + 1; i++)
#define rev(i, n) for (int i = n - 1; i >= 0; i--)
#define all(A) A.begin(), A.end()
#define itr(A, l, r) A.begin() + l, A.begin() + r
#define debug(var) cout << #var << " = " << var << endl;
typedef long long ll;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p)
{
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << (i + 1 != (int)v.size() ? " " : "");
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < (int)v.size(); i++)
    {
        os << v[i] << endl;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, const vector<vector<vector<T>>> &v)
{
    int n = v.size();
    int m = v[0].size();
    int p = v[0][0].size();
    rep(k, p)
    {
        os << "k = " << k << endl;
        rep(i, n)
        {
            rep(j, m)
            {
                os << v[i][j][k];
                if (j < m - 1)
                {
                    os << " ";
                }
                else
                {
                    os << endl;
                }
            }
        }
    }
    return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    for (T &in : v)
        is >> in;
    return is;
}

template <typename T, typename S>
ostream &operator<<(ostream &os, map<T, S> &mp)
{
    for (auto &[key, val] : mp)
    {
        os << key << ":" << val << " ";
    }
    cout << endl;
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, set<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, multiset<T> st)
{
    auto itr = st.begin();
    for (int i = 0; i < (int)st.size(); i++)
    {
        os << *itr << (i + 1 != (int)st.size() ? " " : "");
        itr++;
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, queue<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, deque<T> q)
{
    while (q.size())
    {
        os << q.front() << " ";
        q.pop_front();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, stack<T> st)
{
    while (st.size())
    {
        os << st.top() << " ";
        st.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T> pq)
{
    while (pq.size())
    {
        os << pq.top() << " ";
        pq.pop();
    }
    return os;
}

template <typename T>
ostream &operator<<(ostream &os, priority_queue<T, vector<T>, greater<T>> mpq)
{
    while (mpq.size())
    {
        os << mpq.top() << " ";
        mpq.pop();
    }
    return os;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    int L = 0;
    int R = 1;
    int ans = 0;
    while(q--){
        char h;
        int t;
        cin >> h >> t;
        t--;
        if(h == 'L'){
            int org_L = L;
            int cnt = 0;
            bool collide = false;
            // Attempt to move L to the target t by moving left (decreasing)
            while(L != t){
                L--;
                cnt++;
                if(L < 0){
                    L += n;
                }
                if(L == R){
                    collide = true;
                    break;
                }
            }
            if(!collide){
                ans += cnt;
            }
            else{
                // Reset L to original position and try moving right (increasing)
                L = org_L;
                cnt = 0;
                while(L != t){
                    L++;
                    cnt++;
                    L %= n;
                    if(L == R){
                        // If collision occurs again, movement is blocked
                        // Depending on problem constraints, handle accordingly
                        break;
                    }
                }
                ans += cnt;
            }
        }
        else{
            int org_R = R;
            int cnt = 0;
            bool collide = false;
            // Attempt to move R to the target t by moving right (increasing)
            while(R != t){
                R++;
                cnt++;
                R %= n;
                if(R == L){
                    collide = true;
                    break;
                }
            }
            if(!collide){
                ans += cnt;
            }
            else{
                // Reset R to original position and try moving left (decreasing)
                R = org_R;
                cnt = 0;
                while(R != t){
                    R--;
                    cnt++;
                    if(R < 0){
                        R += n;
                    }
                    if(R == L){
                        // If collision occurs again, movement is blocked
                        // Depending on problem constraints, handle accordingly
                        break;
                    }
                }
                ans += cnt;
            }
        }
        // Debugging output (you can remove these in the final version)
        // Replace `debug` with `cout` or appropriate logging if necessary
    }
    cout << ans << endl;
}