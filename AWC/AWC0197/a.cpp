#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    string res;
    rep(i,n){
        int a;
        cin >> a;
        if(a % 2 == 1) res += "A";
        else res += "T";
    }
    cout << res << endl;
    
    return 0;
}