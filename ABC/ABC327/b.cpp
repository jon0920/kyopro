#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    ll b;
    cin >> b;
    for(int a = 1; a <= 15; a++){
        ll sum = 1;
        rep(i,a) sum *= a;
        if(sum == b){
            cout << a << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}