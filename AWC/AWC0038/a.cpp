#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){

    int n;
    cin >> n;
    int mx = 0;
    rep(i,n){
        int h;
        cin >> h;
        if(h > mx){
            cout << i + 1 << " ";
            mx = h;
        }
    }
    cout << endl;

    return 0;
}