#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    int sum = 0;
    rep(i,n - 1){
        int a;
        cin >> a;
        sum += a;
    }
    cout << -sum << endl;
    
    return 0;
}