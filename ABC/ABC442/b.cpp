#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
    
    int q;
    cin >> q;
    int vol = 0;
    bool play = false;
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            vol++;
        }
        else if(a == 2){
            if(vol > 0) vol--;
        }
        else{
            if(play) play = false;
            else play = true;
        }
        if(vol >= 3 && play) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}