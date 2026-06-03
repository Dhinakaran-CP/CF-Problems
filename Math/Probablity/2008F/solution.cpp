#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
#define INF (int)1e12+1
#define f first
#define s second
#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()
using vll = vector<long long>;
using vi = vector<int>;
using vc = vector<char>;
using vs = vector<string>;
ll MOD = 1e9+7;
constexpr int inf = 1e18;
#define pb push_back
#define pf push_front
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define rep(i,n) for (int i=0;i<(n);i++)
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


ll power(ll base , ll exp){
    ll res = 1;
    base %= MOD;
    while(exp>0){
        if (exp%2==1)res = (res*base)%MOD;
        base = (base*base)%MOD;
        exp/=2;
    }

    return res;
}

ll modInverse(ll a){
    return power(a,MOD-2);
}

void solve(){
    int n;
    cin >> n;
    vll v(n);
    rep(i,n)cin >> v[i];

    ll sum_a = 0 , sq_a = 0;

    rep(i,n){
        sum_a = (sum_a + v[i])%MOD;
        sq_a = (sq_a + (v[i]*v[i])%MOD)%MOD;
    }

    ll p = (sum_a*sum_a)%MOD;
    p = (p-sq_a+MOD)%MOD;

    ll q = n*(n-1);
    q %= MOD;

    ll res = (p * modInverse(q))%MOD;

    cout << res << "\n";

}
int32_t main() {
    ios_base::sync_with_stdio(0);

    cin.tie(0);
    int t =1;


   cin >>t;

    while(t--){
        solve();
    }
    return 0;
}
