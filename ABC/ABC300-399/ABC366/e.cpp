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
    ll n,d;
    cin >> n >> d;
    vector<pair<ll,ll>> vp(n);
    cin >> vp;
    vector<ll> x(n),y(n);
    rep(i,n){
        x[i] = vp[i].first;
        y[i] = vp[i].second;
    }
    sort(all(x));
    sort(all(y));
    auto manhatten_memo = [](vector<ll> v,ll left,ll right){
        ll n = v.size();
        v.push_back(left-1);
        v.push_back(right+1);
        sort(all(v));
        // debug(v);
        vector<ll> ans(right-left+1);    
        int idx_right = (n+1)/2+1;
        int idx_left =n/2+1;
        // debug(vector<int>({idx_left,idx_right}));
        ll now = 0;
        ll factor = 2;
        for(int i=idx_right;i<=n;i++){
            for(int j=v[i];j<v[i+1];j++){
                ans[j-left] = now;
                now += factor;
            }
            factor += 2;
        }
        now = 0;
        factor = 2;
        for(int i=idx_left;i>1;i--){
            for(int j=v[i-1];j>v[i-2];j--){
                ans[j-left] = now;
                now += factor;
            }
            factor += 2;
        }
        return ans;
    };
    vector<ll> memo_x = manhatten_memo(x,-2e6,2e6);
    vector<ll> memo_y = manhatten_memo(y,-2e6,2e6);
    // debug(x);
    // debug(y);
    ll base_x = 0;
    rep(i,n){
        base_x += abs(x[i]-x[n/2]);
    }
    ll base_y = 0;
    rep(i,n){
        base_y += abs(y[i]-y[n/2]);
    }
    // debug(vector<ll>({base_x,base_y}));
    ll ans = 0;
    for(int cx=-2e6;cx<=2e6;cx++){
        if(base_x+base_y+memo_x[cx+2e6]>d){
            continue;
        }
        // cout << cx << " " << base_x+base_y+memo_x[cx+2e6] << endl;
        ll target =  d-base_x -base_y- memo_x[cx+2e6];
        // debug(target);
        ll ng = n/2-1;
        ll ok = 2e6+1;
        while(abs(ng-ok)>1){
            ll mid = ng+ok;
            mid /= 2;
            if(memo_y[mid+2e6] > target){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        ll upper = ok;
        ok = n/2;
        ng = -2e6-1;
        // for(int i=-10;i<=10;i++){
        //     cout << memo_y[i+2e6] << " ";
        // }
        // cout << endl;
        while(abs(ng-ok)>1){
            ll mid = ng+ok;
            mid /= 2;
            if(memo_y[mid+2e6] <= target){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        // debug(ok);
        ll lower = ok;
        // debug(vector<ll>({lower,upper}));
        ans += upper - lower;
    }
    cout << ans << endl;
}