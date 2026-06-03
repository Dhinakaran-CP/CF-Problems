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

    int n,x;
    cin >> n >> x;
    ll triplets = 0;

    for (int a=1;a<=x;a++){
        for (int b=1;b<=x-a;++b){

            if (a*b >= n)break;

            ll c1 = x-a-b;
            ll c2 = (n-a*b)/(a+b);

            ll c = min(c1,c2);
            if (c >=1)triplets += c;
            else break;
        }
    }
    cout << triplets << "\n";
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
