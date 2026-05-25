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

void solve(){

    string x;cin >> x;
    vi cnt(10,0);
    for (char c:x)cnt[c-'0']++;
    cnt[1]--;cnt[6]--;cnt[8]--;cnt[9]--;
    string prefix="";
    int r=0;
    for (int i=1;i<=9;i++){
        while(cnt[i]>0){
            prefix += to_string(i);
            r = (r*10 + i)%7;
            cnt[i]--;
        }
    }

    r = (r*10000)%7;
    int target = (7-r)%7;
    vi a{1,6,8,9};
    string perm ="";
    do{
        int val = 0;
        for (int d:a){
            val = val*10 + d;
        }
        if (val%7==target){
            perm = to_string(val);
            break;
        }
    }while(next_permutation(all(a)));

    string suffix="";
    rep(i,cnt[0])suffix+='0';

    cout << prefix << perm << suffix ;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
