#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int w, b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbw";
    rep(i,s.size()){
        int tw = 0, tb = 0;
        rep(j,w + b){
            if(s[(i + j) % 12] == 'w') tw++;
            else tb++;
        }
        if(tw == w && tb == b){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    
    return 0;
}