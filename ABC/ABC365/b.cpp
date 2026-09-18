#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n){
        cin >> a[i];
        b[i] = a[i];
    }

    sort(b.rbegin(), b.rend());
    rep(i,n){
        if(a[i] == b[1]){
            cout << i + 1 << endl;
            return 0;
        }
    }
    
    return 0;
}