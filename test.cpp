#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define NYAN ios::sync_with_stdio(false);cin.tie(nullptr);cout << fixed << setprecision(10);
typedef long long ll;
typedef __int128_t i128;
typedef long double ld;
#define pl pair<long long,long long>
#define vl vector<long long>
#define vp vector<pair<long long,long long>>
#define vm vector<mint>

void Yes(bool b=1) { cout << (b==1?"Yes":"No") << "\n"; }
void YES(bool b=1) { cout << (b==1?"YES":"NO") << "\n"; }
void No(bool b=1) { cout << (b==1?"No":"Yes") << "\n"; }
void NO(bool b=1) { cout << (b==1?"NO":"YES") << "\n"; }
void CIN() {}
template <typename T, class... U> void CIN(T &t, U &...u) { cin >> t; CIN(u...); }
void COUT() { cout << "\n"; }
template <typename T, class... U, char sep = ' '> void COUT(const T &t, const U &...u) { cout << t; if (sizeof...(u)) cout << sep; COUT(u...); }
#define dump(x) cerr << #x << ":"<< x << "\n";
#define vdump(x) rep(repeat, sz(x)) cerr << repeat << ":" << x[repeat] << "\n";

#define bp __builtin_popcount
#define ALL(x) x.begin(),x.end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for (ll i = n; i >= 0LL; i--)
#define reps(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define sz(x) (ll)x.size()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template<class T> using v = vector<T>;

long double PI = 3.14159265358979;
#define INF32 2147483647
#define INF64 9223372036854775807
// using mint = modint998244353;
using mint = modint1000000007;
//右下左上 右下 左下 左上 右上
ll xd[]={0,1,0,-1,1,1,-1,-1};
ll yd[]={1,0,-1,0,1,-1,-1,1};
ll rmax(ll a,ll b){return max(a,b);}
ll rmin(ll a,ll b){return min(a,b);}
ll rzero(){return 0;}
ll rinf(){return INF64;}

/* SOLVE BEGIN ************************************************************************** */

void solve()
{
  ll n;
  cin >> n;
  ll ans = 0;
  
  //平方数
  vl he;
  reps(i, 1, n+1){
    if(i * i <= n) he.emplace_back(i * i);
    else break;
  }
  
  vl a(n+1, 1), sosu(n+1);
  for(ll i=2; i<=n; i++){
    if(sosu[i])continue;
    a[i] *= i;
    for(ll j=i*2; j<=n; j+=i){
      sosu[j]=1;
      ll k = j, cnt = 0;
      while(k%i==0){
        k /= i;
        cnt++;
      }
      if(cnt%2)a[j] *= i;
    }
  }
  
  reps(i, 1, n+1){
    ll x = n / a[i];
    auto iter = upper_bound(ALL(he), x);
    ans += iter - he.begin();
  }

  cout << ans << "\n";
}

int main()
{
  NYAN
  solve();
  return 0;
}