#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(n + 1);
    rep(i,n) cnt[i + 1] = cnt[i] + (s[i] == 'o');

    auto check = [&](double x, int n, int k, string s, vector<int> cnt) -> bool {
        vector<double> p(n + 1, 0.0);
        rep(i,n){
            double d = (s[i] == 'o' ? (1.0 - x) : -x);
            p[i + 1] = p[i] + d;
        }

        double min_p = 1e18;
        int l = 0;
        for(int r = 1; r <= n; r++){
            while(l <= r && cnt[l] <= cnt[r] - k){
                min_p = min(min_p, p[l]);
                l++;
            }
            if(min_p != 1e18 && p[r] - min_p >= -1e-11) return true;
        }
        return false;
    };

    double low = 0.0, high = 1.0;
    rep(_,60){
        double mid = (low + high) / 2.0;
        if(check(mid, n, k, s, cnt)) low = mid;
        else high = mid;
    }

    cout << fixed << setprecision(17);
    cout << low << endl;
    
    return 0;
}