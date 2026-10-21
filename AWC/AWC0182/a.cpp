#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n; 
    rep(i,n){
        int a, b;
        cin >> a >> b;
        if(a > b) cout << "Left" << endl;
        else if(a < b) cout << "Right" << endl;
        else cout << "Balanced" << endl;
    }
    
    return 0;
}