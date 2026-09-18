#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '@'){
            s[i] = '.';
            d--;
            if(d == 0) break;
        }
    }

    cout << s << endl;

    return 0;
}