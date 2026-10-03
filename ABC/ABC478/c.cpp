#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;
    sort(b.begin(), b.end());

    int l = -1, r = -1;
    rep(i,n){
        if(a[i] != b[i]){
            if(l == -1) l = i;
            r = i;
        }
    }
    if(l == -1){
        cout << "Yes" << endl;
    } else if(r - l + 1 <= k){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}