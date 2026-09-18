#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    rep(i,n){
        int h, m;
        cin >> h >> m;
        h += m / 60;
        m %= 60;
        int d = h / 24;
        h %= 24;
        cout << d << " " << h << " " << m << endl;
    }
    
    return 0;
}