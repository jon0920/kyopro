#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    string res;
    rep(i,n){
        if((i / k) % 2 == 0) res += "R";
        else res += "B";
    }
    cout << res << endl;
    
    return 0;
}