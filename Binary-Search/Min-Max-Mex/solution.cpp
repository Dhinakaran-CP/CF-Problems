#include <bits/stdc++.h>
using namespace std;

#define int long long
using ll = long long;
#define INF (int)1e18
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

const int MAX = 1e6 + 5;



bool check(int k , ll mini,vll& v){
    if (mini == 0)return true;

    vi freq(mini,0);

    int have = 0;
    int needed = 0;

    for (auto x:v){
        if (x<mini){
            if (freq[x]==0){
                ++have;
            }

            freq[x]++;
        }

        if (have == mini){
            needed++;
            fill(all(freq),0);
            have = 0;
        }
    }


    return needed >= k;

    
}


void solve(){
    
    int n ,k;
    cin >> n >> k;
    vll v(n);
    rep(i,n)cin >> v[i];

    int lo = 0;
    int hi = n+1;
    int ans = 0;
    while(lo <= hi){
        int mid  = lo + ((hi-lo)>>1);

        if (check(k,mid,v)){
            ans = mid;
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
        
    }

    cout << ans <<"\n";


}
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t =1;

    cin >> t;


    while(t--){
    solve();
    }
    return 0;
}
