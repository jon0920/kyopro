#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> p(n), ref(n);
    iota(p.begin(), p.end(), 0);
    iota(ref.begin(), ref.end(), 0);
    vector<vector<int>> c(n, vector<int>(n));
    rep(i,n) rep(j,n) cin >> c[i][j];

    auto check = [&](vector<int> p) -> bool {
        int swap_cnt = 0;
        rep(i,n){
            if(ref[i] != p[i]){
                swap(p[i], p[p[i]]);
                swap_cnt++;
            }
        }
        if(swap_cnt <= k) return true;
        else return false;
    };

    ll ans = 0;
    do{
        if(!check(p)) continue;
        ll sum = 0;
        rep(i,n){
            sum += c[p[i]][p[(i + 1) % n]];
        }
        ans = max(ans, sum);
    }while(next_permutation(p.begin(), p.end()));
    cout << ans << endl;

    return 0;
}