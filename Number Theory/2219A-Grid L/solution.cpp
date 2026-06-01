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


void solve(){
    ll p,q;
    cin >> p >> q;
    ll k = 2*p + 4*q+1;

    ll x = -1;
    for (ll i=sqrt(k);i>=3;--i){
        if (k%i==0){
            x=i;
            break;
        }
    }
    
    if (x==-1){
        cout << "-1\n";
        return;
    }


    ll y = k/x;

    if (abs(x-y)<=2*p){
        ll n = (x-1)/2;
        ll m = (y-1)/2;
        cout << n << " " << m << "\n";
    }
    else{
        cout << "-1\n";
    }
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
