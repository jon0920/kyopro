#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

struct S{
    int L, R, V;
};

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<S> cand(n);
    rep(i,n) cin >> cand[i].L >> cand[i].R >> cand[i].V;

    int ans = 1e9;    
    for(int b1 = 0; b1 < (1 << n); b1++){
        if(__builtin_popcount(b1) == n - k){
            vector<int> vec;
            rep(i,n) if(b1 & (1 << i)) vec.push_back(i);
            int res = 0;
            for(int b2 = 0; b2 < (1 << (n - k)); b2++){
                vector<int> t(110);
                int sum = 0;
                rep(i,n - k){
                    if(b2 & (1 << i)){
                        auto [l, r, v] = cand[vec[i]];
                        t[l]++; t[r]--;
                        sum += v;
                    }
                }
                rep(i,101) t[i + 1] += t[i];
                bool ok = true;
                rep(i,101) if(t[i] >= 2) ok = false;
                if(ok) res = max(res, sum);
            }
            ans = min(ans, res);
        }
    }

    cout << ans << endl;
    
    return 0;
}