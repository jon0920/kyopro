#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];

    int ok = x[n - 1] - x[0];
    int ng = -1;

    auto solve = [&](int y){
        int cnt = 1, left = x[0];
        for(int i = 1; i < n; i++){
            if(x[i] - left > y){
                cnt++;
                left = x[i];
            }
        }
        return cnt <= k;
    };

    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}