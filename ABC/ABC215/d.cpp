#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

set<int> primes;
vector<int> ans;

void pf(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i != 0) continue;
        primes.insert(i);
        while(x % i == 0){
            x /= i;
        }
    }
    if(x != 1) primes.insert(x);
    return;
}

bool solve(int x){
    for(int i = 2; i * i <= x; i++){
        if(x % i != 0) continue;
        if(primes.count(i)) return false;
        while(x % i == 0){
            x /= i;
        }
    }    
    if(x != 1 && primes.count(x)) return false;
    return true;
}

int main(){

    int n, m;
    cin >> n >> m;
    rep(i,n){
        int a;
        cin >> a;
        pf(a);
    }

    ans.push_back(1);
    for(int i = 2; i <= m; i++){
        if(solve(i)) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for(auto x : ans) cout << x << endl;

    return 0;
}