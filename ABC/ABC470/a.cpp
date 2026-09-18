#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(i % 3 == 0) cout << "Fizz" << endl;
        else cout << i << endl;
    }
    
    return 0;
}