#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, k;
    cin >> n >> k;
    rep(i,n){
        int a;
        cin >> a;
        if(a % k == 0) cout << a / k << " ";
    }
    cout << endl;
    
    return 0;
}