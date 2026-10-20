#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

using ld = long double;

int main(){
    
    int t;
    cin >> t;
    while(t--){
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        sort(a.begin(), a.end());

        auto solve = [&](ld val) -> bool {
            ll cnt = 0;
            rep(i,n){
                if(a[i] >= val) cnt++;
            }

            ll cut = 0;
            for(int i = n - 1; i >= 0; i--){
                ld cur = a[i];
                ll pieces = 1;
                while(cur >= val * 2){
                    cur /= 2;
                    pieces *= 2;

                    if(cut + pieces - 1 >= k){
                        return cnt + k >= x;
                    }
                }
                cut += pieces - 1;
            }

            ll rem = max(0LL, cnt + cut - (k - cut));
            return rem >= x;
        };

        ld ok = 0.0;
        ld ng = a.back() + 1.0L;
        rep(_,100){
            ld mid = (ok + ng) / 2;

            if(solve(mid)) ok = mid;
            else ng = mid;
        }

        cout << fixed << setprecision(17);
        cout << ok << endl;
    }
    
    return 0;
}