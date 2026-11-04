#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    int mx = *max_element(a.begin(), a.end());
    vector<int> primes;
    vector<int> fact(mx + 1, 1);
    for(int i = 2; i < mx + 1; i++){
        if(fact[i] == 1){
            primes.push_back(i);
            fact[i] = i;
        }
        for(int p : primes){
            if(i * p > mx || p > fact[i]) break;
            fact[i * p] = p;
        }
    }

    vector<int> cnt(mx + 1);
    for(int x : a){
        cnt[x]++;
    }
    for(int p : primes){
        for(int i = mx / p; i >= 0; i--){
            cnt[i] += cnt[i * p];
        }
    }

    vector<int> ans(mx + 1);
    for(int i = 1; i < mx + 1; i++){
        if(cnt[i] >= k) ans[i] = i;
    }
    for(int p : primes){
        for(int i = 1; i < mx / p + 1; i++){
            if(ans[i * p] < ans[i]) ans[i * p] = ans[i];
        }
    }

    for(int x : a) cout << ans[x] << endl;
    
    return 0;
}