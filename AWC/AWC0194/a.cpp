#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n; ll a;
    cin >> n >> a;
    rep(i,n){
        cout << a << endl;
        a *= 2;
    }
    
    return 0;
}