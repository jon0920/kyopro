#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++) cin >> h[i];
    vector<int> c(n + 1);
    for(int i = 2; i < n; i++){
        if(h[i] < h[i - 1] && h[i] < h[i + 1]) c[i]++;
    }
    rep(i,n) c[i + 1] += c[i];

    while(q--){
        int l, r;
        cin >> l >> r;
        r--;
        cout << c[r] - c[l] << endl;
    }
    
    return 0;
}