#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n, k;
    cin >> n >> k;
    string res;
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a - b >= k) res += "L";
        else res += "S";
    }

    cout << res << endl;
    
    return 0;
}