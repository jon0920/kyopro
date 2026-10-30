#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)

int main(){
    
    int n;
    cin >> n;
    int pos = 0;
    rep(i,n){
        char d; int x;
        cin >> d >> x;
        if(d == 'R') pos += x;
        else pos -= x;

        cout << pos << endl;
    }
    
    return 0;
}