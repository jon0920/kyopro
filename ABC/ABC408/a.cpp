#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n, s;
    cin >> n >> s;
    vector<int> t(n);
    int bef = 0;
    bool flag = false;
    rep(i,n){
        cin >> t[i];
        if(t[i] - bef <= s){
            bef = t[i];
            continue;
        }
        else{
            flag = true;
            break;
        }
    }
    cout << (flag ? "No" : "Yes") << endl;
    
    
    return 0;
}