#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int suma = 0, sumb = 0;
    rep(i,9){
        int a;
        cin >> a;
        suma += a;
    }
    rep(i,8){
        int b;
        cin >> b;
        sumb += b;
    }
    cout << suma - sumb + 1 << endl;
    
    return 0;
}