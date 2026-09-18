#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

const ll mx = 10'000'010;

vector<ll> eratosthenes(){
    vector<bool> is_prime(mx + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(ll i = 2; i * i <= mx; i++){
        if(is_prime[i]){
            for(ll j = i * i; j <= mx; j += i){
                is_prime[j] = false;
            }
        }
    }
    vector<ll> P;
    for(ll i = 2; i <= mx; i++){
        if(is_prime[i]) P.push_back(i);
    }
    return P;
}

int main(){
    
    vector<ll> primes;
    primes = eratosthenes();

    string s;
    cin >> s;
    set<char> st;
    for(char c : s) st.insert(c);

    for(ll x : primes){
        string t = to_string(x);
        if(t.size() != s.size()) continue;
        map<char,int> mp;
        bool ok = true;
        vector<bool> used(10);
        rep(i,(int)t.size()){
            if(!mp.count(s[i])){
                if(used[t[i] - '0']){
                    ok = false;
                    break;
                }
                mp[s[i]] = t[i] - '0';
                used[t[i] - '0'] = true;
            } else {
                if(mp[s[i]] != t[i] - '0'){
                    ok = false;
                    break;
                }
            }
        }
        if(ok){
            cout << x << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    
    return 0;
}