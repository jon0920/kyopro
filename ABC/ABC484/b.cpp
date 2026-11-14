#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int k;
    cin >> k;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    sort(a.begin(), a.end());
    if(a.back() != 9){
        cout << -1 << endl;
    } else {
        cout << a[0] << endl;
    }
    
    return 0;
}