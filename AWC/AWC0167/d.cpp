#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> f(n);
    rep(i,n - 1){
        if((a[i] + a[i + 1]) & 1){
            f[i] = max(0, i - 1);
        } else {
            f[i] = i + 1;
        }
    }
    f[n - 1] = n - 1;

    auto doubling = [n](vector<int> mapping){
        vector<int> res(n);
        rep(i,n) res[i] = mapping[mapping[i]];
        return res;
    };

    int crr = 0;
    vector<int> mapping = f;
    ll rem = k;

    while(rem){
        if(rem % 2 == 1){
            crr = mapping[crr];
            rem--;
        }
        mapping = doubling(mapping);
        rem /= 2;
    }

    cout << crr + 1 << endl;
    
    return 0;
}