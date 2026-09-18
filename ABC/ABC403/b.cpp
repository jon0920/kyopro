#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    string t, u;
    cin >> t >> u;
    bool flag;

    for(int i = 0; i <= t.size() - u.size(); i++){
        flag = true;
        rep(j,u.size()){
            if(t[i + j] != '?' && t[i + j] != u[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}