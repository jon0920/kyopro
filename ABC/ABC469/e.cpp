#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> sum(n + 1);
    rep(i,n) sum[i + 1] = sum[i] + (s[i] == 'o');

    auto solve = [&](double x){
        vector<double> p(n + 1);
        rep(i,n){
            if(s[i] == 'o') p[i + 1] = p[i] + (1 - x);
            else p[i + 1] = p[i] - x;
        }

        double min_p = 1e18;
        int l = -1;
        for(int r = 1; r <= n; r++){
            int target = sum[r] - k;
            while(l + 1 <= n && sum[l + 1] <= target){
                l++;
                min_p = min(min_p, p[l]);
            }
            if(l >= 0 && p[r] - min_p >= 0.0) return true;
        }

        return false;
    };

    double ok = 0.0, ng = 1.0;
    rep(_,80){
        double mid = (ok + ng) / 2.0;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << fixed << setprecision(17);
    cout << ok << endl;
    
    return 0;
}