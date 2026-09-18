#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, x;
    cin >> n >> x;
    int sum = 0;
    rep(i,n){
        int a;
        cin >> a;
        if(x >= a) sum += a;
    }
    cout << sum << endl;
    
    return 0;
}