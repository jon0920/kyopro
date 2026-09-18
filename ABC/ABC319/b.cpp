#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;

    rep(i,n + 1){
        bool check = true;
        for(int j = 1; j <= 9; j++){
            if(n % j != 0) continue;
            if(i % (n / j) == 0){
                cout << j;
                check = false;
                break;
            }
        }
        if(check) cout << '-';
    }
    cout << endl;
    
    return 0;
}