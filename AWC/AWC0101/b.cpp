#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    auto solve = [&](int x){
        rep(i,n){
            if(i == 0){
                if(a[i] > x) return false;
            } else {
                if(a[i] > x + 1) return false;
            }
        }
        return true;
    };

    int ng = 0, ok = 1e9;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        if(solve(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
    
    return 0;
}