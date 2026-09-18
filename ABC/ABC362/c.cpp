#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    vector<ll> res(n);
    ll sum = 0;
    rep(i,n){
        cin >> l[i] >> r[i];
        res[i] = l[i];
        sum += l[i]; 
    }

    if(sum > 0){
        cout << "No" << endl;
        return 0;
    }

    int pos = 0;
    while(sum < 0 && pos < n){
        ll s = r[pos] - res[pos];
        if(sum + s <= 0){
            sum += s;
            res[pos] = r[pos];
        }
        else{
            res[pos] -= sum;
            sum = 0;
            break;
        } 
        pos++;
    }

    if(sum != 0) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        for(auto x : res) cout << x << " ";
    }
    
    return 0;
}