#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b = a;

    for(int i = 1; i < n - 1; i++){
        if(a[i - 1] == a[i + 1] && a[i - 1] != a[i]) b[i] = 0;
    }

    for(auto bi : b) x ^= bi;
    cout << x << endl;

    return 0;
}