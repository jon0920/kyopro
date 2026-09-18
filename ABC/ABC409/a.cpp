#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    string t, a;
    cin >> t >> a;
    bool flag = false;
    
    rep(i,n){
        if(t[i] == 'o' && a[i] == 'o'){
            flag = true;
        }
    }
    
    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}