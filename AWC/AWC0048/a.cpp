#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    rep(i,n){
        string s;
        int k;
        cin >> s >> k;
        if(k % 2 == 0){
            cout << s << endl;
        } else {
            if(s == "Yes") cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }

    return 0;
}