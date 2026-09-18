#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int n;
    cin >> n;
    vector<string> s(n,string(n,'?'));
    
    for(int i = 1; i <= n; i++){
        int j = n + 1 - i;
        if(i > j) continue;
        else{
            if(i % 2 != 0){
                for(int k = i; k <= j; k++){
                    for(int l = i; l <= j; l++){
                        s[k-1][l-1] = '#';
                    }
                }
            }
            else{
                for(int k = i; k <= j; k++){
                    for(int l = i; l <= j; l++){
                        s[k-1][l-1] = '.';
                    }
                }
            }
        }
    }

    rep(i,n) cout << s[i] << endl;

    return 0;
}