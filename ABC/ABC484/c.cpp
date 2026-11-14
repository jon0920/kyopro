#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];

    int l = -1;
    rep(i,n){
        if(a[i] != b[i]){
            l = i;
            break;
        }
    }
    if(l == -1){
        cout << "Yes" << endl;
        return 0;
    }

    int r = -1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] != b[i]){
            r = i;
            break;
        }
    }

    int len = 0;
    while(l + 1 + len < n && a[len + l + 1] == b[len + l]) len++;

    int lo = max(l + 1, r), hi = l + len;
    for(int i = lo; i <= hi; i++){
        if(a[l] == b[i]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    len = 0;
    while(l + 1 + len < n && a[l + len] == b[l + len + 1]) len++;

    hi = l + len;
    for(int i = lo; i <= hi; i++){
        if(a[i] == b[l]){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    
    return 0;
}