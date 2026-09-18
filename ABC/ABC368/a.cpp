#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    for(int i = n - k; i < n; i++){
        cout << a[i] << " ";
    }

    for(int i = 0; i < n - k; i++){
        cout << a[i] << " ";
    }
    
    cout << endl;
    return 0;
}