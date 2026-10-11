#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<ll> L(n), R(n);
    for(int i = 1; i < n; i++) cin >> L[i];
    rep(i,n - 1) cin >> R[i];

    vector<ll> min_L = L;
    vector<ll> min_R = R;
    for(int i = n - 2; i >= 0; i--){
        min_L[i] = min(min_L[i], min_L[i + 1]);
    }
    for(int i = 1; i < n; i++){
        min_R[i] = min(min_R[i], min_R[i - 1]);
    }

    while(q--){
        int s, t;
        cin >> s >> t;
        s--, t--;
        if(s == 0){
            cout << R[0] << endl;
        } else if(s == n - 1){
            cout << L[n - 1] << endl;
        } else {
            if(s < t){
                cout << min(R[s], L[s] + min_R[s - 1]) << endl;
            } else {
                cout << min(L[s], R[s] + min_L[s + 1]) << endl;
            }
        }
    }
    
    return 0;
}