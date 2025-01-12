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

    int main()
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> hand(n);
        rep(i, n)
        {
            if (s[i] == 'R')
            {
                hand[i] = 0;
            }
            if (s[i] == 'P')
            {
                hand[i] = 1;
            }
            if (s[i] == 'S')
            {
                hand[i] = 2;
            }
        }
        // debug(hand);
        vector<vector<int>> dp(n, vector<int>(3, -1));
        rep(j, 3)
        {
            int tmp = j - hand[0];
            if (tmp < 0)
            {
                tmp += 3;
            }
            // debug(tmp);
            if (tmp == 0)
            {
                dp[0][j] = 0;
            }
            if (tmp == 1)
            {
                dp[0][j] = 1;
            }
            if (tmp == 2)
            {
                dp[0][j] = -1;
            }
        }
        // cout << dp << endl;
        auto chmax = [](auto &a, auto b)
        { a = max(a, b); };
        rep(i, n - 1)
        {
            rep(j, 3)
            {
                if (dp[i][j] == -1)
                {
                    continue;
                }
                rep(next, 3)
                {
                    if (j == next)
                    {
                        continue;
                    }
                    int tmp = next - hand[i + 1];
                    if (tmp < 0)
                    {
                        tmp += 3;
                    }
                    // debug(tmp);
                    if (tmp == 0)
                    {
                        chmax(dp[i+1][next],dp[i][j]);
                    }
                    if (tmp == 1)
                    {
                        chmax(dp[i+1][next],dp[i][j]+1);
                    }
                }
            }
        }
        // cout << dp << endl;
        int ans = *max_element(all(dp[n-1]));
        cout << ans << endl;
    }