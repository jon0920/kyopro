#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        cout << (a + b) % 24 << endl;
    }
    
    return 0;
}