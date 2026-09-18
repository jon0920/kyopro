#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> imos(200010);
    rep(i,n){
        int l, r;
        cin >> l >> r;
        imos[l]++;
        imos[r]--;
    }
    for(int i = 1; i <= 200005; i++) imos[i] += imos[i - 1];
    for(int i = 1; i <= 200005; i++){
        if(imos[i - 1] == 0 && imos[i] != 0) cout << i << " ";
        if(imos[i - 1] != 0 && imos[i] == 0) cout << i << endl;
    }
    
    return 0;
}