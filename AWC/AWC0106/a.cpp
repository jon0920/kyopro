#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int cnt = 0, nh = -1;
    rep(i,n){
        if(nh == h[i]){
            cnt++;
        } else {
            cnt = 1;
            nh = h[i];
        }
        if(cnt == k){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}