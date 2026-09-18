#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    for(int i = n; i >= 1; i--){
        cout << i;
        if(i != 1) cout << ',';
    }
    cout << endl;

    return 0;
}